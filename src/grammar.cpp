#include "grammar.h"
using namespace std;

regex Grammar::specialCharacterRegex  = regex("[;=<>*+\\[\\]()|{} ]"); /// Regex that matches for JSGF special characters that cannot be unescaped in non-quoted Tokens

Grammar::Grammar() /// Default constructor. Creates an empty Grammar object with the grammar name set to "default"
{
    name = "default";
}

/**
  * Constructor with name.
  * \param string grammarName - name of the Grammar to be created
  */
Grammar::Grammar(string grammarName)
{
    name = grammarName;
}

Grammar::Grammar(ifstream & inputStream) {
    std::string statement = "";
    while(getline(inputStream, statement, ';')) {
        statement = Grammar::trimString(statement);
        //Remove extra whitespace between characters
        statement = Grammar::replaceAll(statement, " {2,}", " ");

        if (Grammar::stringStartsWith(statement, "#"))
        {
            continue; // Line is a comment, skip it.
        }
        else if (Grammar::stringStartsWith(statement, "grammar "))
        {
            vector<string> parts = Grammar::splitString(statement, " ");
            setName(parts[1]);
        }
        else if (Grammar::stringStartsWith(statement,"public <"))
        {
            statement = Grammar::replaceFirst(statement, "public ", "");
            vector<string> parts = Grammar::splitString(statement, "=");
            string ruleName = Grammar::replaceAll(parts[0],"<|>", "");
            ruleName = Grammar::trimString(ruleName);
            Expansion * exp = Grammar::parseExpansionsFromString(parts[1]);
            addRule(shared_ptr<Rule>(new Rule(ruleName, true, shared_ptr<Expansion>(exp))));
        }
        else if (Grammar::stringStartsWith(statement,"<"))
        {
            vector<string> parts = Grammar::splitString(statement, "=");
            string ruleName = Grammar::replaceAll(parts[0],"<|>", "");
            ruleName = Grammar::trimString(ruleName);
            Expansion * exp = Grammar::parseExpansionsFromString(parts[1]);
            addRule(shared_ptr<Rule>(new Rule(ruleName, false, shared_ptr<Expansion>(exp))));
        }
    }
}

Grammar::~Grammar() /// Default destructor, removes its ownership of Rule objects
{
    for(shared_ptr<Rule> & r : rules)
    {
        r.reset();
    }
}

std::string Grammar::getName() {
    return name;
}

void Grammar::setName(std::string s) {
    name = s;
}

bool Grammar::writeGrammar(std::ofstream & outputStream) {
    outputStream << getText();
}

/**
  * Adds the specified Rule to the Grammar.
  * \param [in] rule
  */
void Grammar::addRule(shared_ptr<Rule> r)
{
    rules.push_back(r);
}

/**
  * Generates the JSGF grammar and returns it as a string.
  * \return string
  */
string Grammar::getText()
{
    string s = "grammar " + name + ";\n";

    for(shared_ptr<Rule> r : rules)
    {
        s += r->getRuleString() + "\n";
    }

    return s;
}

/**
  * Returns the rule name of the public rule that matches the test string. If no matching public rule is found, an empty string is returned.
  * \param string String to test against public rules.
  * \return string
  */
std::string Grammar::getMatchingPublicRule(std::string test) {
    test = Grammar::trimString(test);
    test = Grammar::replaceAll(test, " {2,}", " ");
    for(shared_ptr<Rule> r : rules) {
        if(r->isPublic()) {
        Matchvector m = matchesRule(r, test);
            if(m.size() != 0) {
                return r->getRuleName();
            }
        }
    }
    return "";
}

/** Returns a MatchResult object that contains info about the rule that the test string matches. An empty MatchResult object is returned if no match is found.
  * \param string String to test against the Grammar's rules
  * \return MatchResult
  */
MatchResult Grammar::match(std::string test) {
    test = Grammar::trimString(test);
    test = Grammar::replaceAll(test, " {2,}", " ");
    for(shared_ptr<Rule> r : rules) {
        Matchvector m = matchesRule(r, test);
        if(m.size() != 0) {
            return MatchResult(r, m);
        }
    }
    return MatchResult();
}

void Grammar::parseGrammar(ifstream f, Grammar & g) {
    std::string statement = "";
    while(getline(f, statement, ';')) {
        statement = Grammar::trimString(statement);
        //Remove extra whitespace between characters
        statement = Grammar::replaceAll(statement, " {2,}", " ");

        if (Grammar::stringStartsWith(statement, "#"))
        {
            continue; // Line is a comment, skip it.
        }
        else if (Grammar::stringStartsWith(statement, "grammar "))
        {
            vector<string> parts = Grammar::splitString(statement, " ");
            g.setName(parts[1]);
        }
        else if (Grammar::stringStartsWith(statement,"public <"))
        {
            statement = Grammar::replaceFirst(statement, "public ", "");
            vector<string> parts = Grammar::splitString(statement, "=");
            string ruleName = Grammar::replaceAll(parts[0],"<|>", "");
            ruleName = Grammar::trimString(ruleName);
            Expansion * exp = Grammar::parseExpansionsFromString(parts[1]);
            g.addRule(shared_ptr<Rule>(new Rule(ruleName, true, shared_ptr<Expansion>(exp))));
        }
        else if (Grammar::stringStartsWith(statement,"<"))
        {
            vector<string> parts = Grammar::splitString(statement, "=");
            string ruleName = Grammar::replaceAll(parts[0],"<|>", "");
            ruleName = Grammar::trimString(ruleName);
            Expansion * exp = Grammar::parseExpansionsFromString(parts[1]);
            g.addRule(shared_ptr<Rule>(new Rule(ruleName, false, shared_ptr<Expansion>(exp))));
        }
    }
}

/**
  * Parses a new Grammar object from string s
  * \param [in] string s
  * \return Grammar *
  */
void Grammar::parseGrammarFromString(string s, Grammar & grammar)
{
    //string noComments = Grammar::replaceAll(s, "(\\#+.*[\\n|\\r|\\v])|([//]+.*[\\n|\\r|\\v])", ""); // Remove all commented out lines
    //vector<string> statements = Grammar::splitString(s, ";"); // Split into statements with each semicolon, NOTE: semicolons within quotes are not protected! Lookbehinds are not supported in C++11 https://stackoverflow.com/questions/14538687/using-regex-lookbehinds-in-c11#14539500
    string statement;
    stringstream ss(s);
    ///https://www.reddit.com/r/cpp_questions/comments/931zq5/any_way_to_simulate_multi_line_regex_with_c11/
    ///Why can't C++11 just have multiline regex? Ugh.

    while(getline(ss, statement, ';')) { /// Note: Semicolons are not protected!
        statement = Grammar::trimString(statement);
        //Remove extra whitespace between characters
        statement = Grammar::replaceAll(statement, " {2,}", " ");

        if (Grammar::stringStartsWith(statement, "#"))
        {
            continue; // Line is a comment, skip it.
        }
        else if (Grammar::stringStartsWith(statement, "grammar "))
        {
            vector<string> parts = Grammar::splitString(statement, " ");
            grammar.setName(parts[1]);
        }
        else if (Grammar::stringStartsWith(statement,"public <"))
        {
            statement = Grammar::replaceFirst(statement, "public ", "");
            vector<string> parts = Grammar::splitString(statement, "=");
            string ruleName = Grammar::replaceAll(parts[0],"<|>", "");
            ruleName = Grammar::trimString(ruleName);
            Expansion * exp = Grammar::parseExpansionsFromString(parts[1]);
            grammar.addRule(shared_ptr<Rule>(new Rule(ruleName, true, shared_ptr<Expansion>(exp))));
        }
        else if (Grammar::stringStartsWith(statement,"<"))
        {
            vector<string> parts = Grammar::splitString(statement, "=");
            string ruleName = Grammar::replaceAll(parts[0],"<|>", "");
            ruleName = Grammar::trimString(ruleName);
            Expansion * exp = Grammar::parseExpansionsFromString(parts[1]);
            grammar.addRule(shared_ptr<Rule>(new Rule(ruleName, false, shared_ptr<Expansion>(exp))));
        }
    }
}

Expansion * Grammar::parseExpansionsFromString(string input)
{
    vector<Expansion *> tokens = parseTokensFromString(input);
    vector<Expansion *> expansionvector1;
    vector<Expansion *> expansionvector2;
    parseRuleReferences(tokens, expansionvector1);
    parseRequiredGroupings(expansionvector1, expansionvector2);
    expansionvector1.clear();
    parseOptionalGroupings(expansionvector2, expansionvector1);
    expansionvector2.clear();
    parseUnaryOperators(expansionvector1, expansionvector2);
    return parseAlternativeSets(expansionvector2);
}

void Grammar::parseUnaryOperators(const vector<Expansion *> & expansions, vector<Expansion *> & output)
{
    vector<Expansion *> tempExp;
    //Parse Plus and Unary operators
    //Note: Each symbol cannot be nested
    bool expansionFound = false; //We found an expansion that a Unary operator can be applied to, check to see if the next char is a unary operator
    Expansion * selectedExpansion;
    vector<Expansion *>::const_iterator expansionIterator = expansions.begin();

    while(expansionIterator != expansions.end())
    {
        if (typeid(*(*expansionIterator)) == typeid(UnparsedSection))
        {
            if (expansionFound)
            {
                UnparsedSection * up = (UnparsedSection *) *expansionIterator;
                if (Grammar::stringStartsWith(up->getSection(), "*"))   // Kleene star operator
                {
                    KleeneStar *ks = new KleeneStar(shared_ptr<Expansion>(selectedExpansion));
                    tempExp.push_back(ks);
                    string newUnprocessedText = up->getSection().replace(up->getSection().find("*"), 1, ""); // Remove the ) token from the  UnparsedSection
                    UnparsedSection * u = new UnparsedSection(Grammar::trimString(newUnprocessedText));
                    tempExp.push_back(u);
                    expansionFound = false;
                }
                else if (Grammar::stringStartsWith(up->getSection(), "+"))     // Plus operator
                {
                    PlusOperator *ps = new PlusOperator(shared_ptr<Expansion>(selectedExpansion));
                    tempExp.push_back(ps);
                    string newUnprocessedText = up->getSection().replace(up->getSection().find("+"), 1, ""); // Remove the ) token from the  UnparsedSection
                    UnparsedSection * u = new UnparsedSection(Grammar::trimString(newUnprocessedText));
                    tempExp.push_back(u);
                    expansionFound = false;
                }
                else
                {
                    tempExp.push_back(selectedExpansion);
                    tempExp.push_back(*expansionIterator);
                    expansionFound = false;
                }
            }
            else
            {
                tempExp.push_back(*expansionIterator);
            }
        }
        else
        {
            if (expansionFound)   // If we already had found an expansion before this and we didnt find a unary operator after it, add it to the vector of processed expansions
            {
                tempExp.push_back(selectedExpansion);
            }
            expansionFound = true;
            selectedExpansion = *expansionIterator;
        }
        expansionIterator++;
    }

    if (expansionFound)   // If we reached the end of the loop with a taggable expansion selected, but didnt add it to the vector of expressions
    {
        tempExp.push_back(selectedExpansion);
    }

    vector<Expansion *> exp = tempExp;

    tempExp.clear();
    bool foundLegalExpansion = false;
    bool foundStart = false;
    bool tagStarted = false;
    string currentTag = "";
    Tag * tagExpansion = nullptr;
    selectedExpansion = nullptr; // Reset the selected Expansion

    expansionIterator = exp.begin();
    //NOTE: A single expansion is allowed to have multiple tags!
    while(expansionIterator != exp.end())
    {
        if (foundLegalExpansion)
        {
            if (foundStart)
            {
                if (typeid(*(*expansionIterator)) == typeid(UnparsedSection))   // Could contain the ending }
                {
                    UnparsedSection * up = (UnparsedSection *) *expansionIterator;
                    if (Grammar::stringStartsWith(up->getSection(), "}"))   // Found the end of the tag!
                    {

                        if(!tagStarted)
                        {
                            tagExpansion = new Tag(shared_ptr<Expansion>(selectedExpansion));
                            tagStarted = true;
                        }

                        tagExpansion->addTag(currentTag);
                        currentTag = ""; // Reset the tag string contents
                        string upText = up->getSection().replace(up->getSection().find("}"), 1, ""); // Remove the } token from the  UnparsedSection
                        upText = Grammar::trimString(upText);

                        if (Grammar::stringEndsWith(upText, "{"))   // Test to see if another tag follows this one
                        {
                            foundStart = true;
                            upText = upText.substr(0, upText.length() - 1); // Remove the last char, which should be the { symbol
                        }
                        else
                        {
                            tagStarted = false;
                            foundStart = false;
                            tempExp.push_back(tagExpansion);
                            foundLegalExpansion = false;
                        }
                        UnparsedSection * u = new UnparsedSection(Grammar::trimString(upText));
                        tempExp.push_back(u);
                    }
                    else
                    {
                        currentTag += up->getSection();
                        delete up;
                    }
                }
                else
                {
                    currentTag += (*expansionIterator)->getText(); // Add the expansions text contents to the tag string
                    delete *expansionIterator;
                }
            }
            else
            {
                // Looking for a starting bracket {
                if (typeid(*(*expansionIterator)) == typeid(UnparsedSection))   // May contain the { we're looking for
                {
                    UnparsedSection * up = (UnparsedSection *) *expansionIterator;
                    if (Grammar::stringEndsWith(up->getSection(), "{"))   // Found the start of the tag!
                    {
                        foundStart = true;
                        string newUnprocessedText = up->getSection().substr(0, up->getSection().length() - 1); // Remove the last char, which should be the { symbol
                        UnparsedSection * u = new UnparsedSection(Grammar::trimString(newUnprocessedText));
                        tempExp.push_back(u); // Add the updated UnprocessedText section to the vector
                    }
                    else
                    {
                        tempExp.push_back(selectedExpansion);
                        tempExp.push_back(*expansionIterator);
                        foundLegalExpansion = false;
                    }
                }
                else     // No tag possible for the selected expansion, but check to see if this expansion can be tagged
                {
                    tempExp.push_back(selectedExpansion);
                    if (!(typeid(*(*expansionIterator)) == typeid(PlusOperator) || typeid(*(*expansionIterator)) == typeid(KleeneStar)))
                    {
                        selectedExpansion = *expansionIterator;
                        tagStarted = false;
                    }
                    else     // current expansion cannot be tagged, begin search for taggable expansion over again
                    {
                        foundLegalExpansion = false;
                        tempExp.push_back(*expansionIterator);
                    }
                }
            }
        }
        else     // Looking for a expansion that is taggable
        {
            if (!(typeid(*(*expansionIterator)) == typeid(PlusOperator) || typeid(*(*expansionIterator)) == typeid(KleeneStar) || typeid(*(*expansionIterator)) == typeid(UnparsedSection)))
            {
                foundLegalExpansion = true; // Found a taggable expansion, select it and start searching for tags
                selectedExpansion = *expansionIterator;
                tagStarted = false;
            }
            else     // Unary operators and UnparsedSections cannot be tagged, pass over them
            {
                tempExp.push_back(*expansionIterator);
            }
        }
        expansionIterator++;
    }

    if (foundLegalExpansion)   // Reached end of loop and had selected a taggable expansion, but no tags found
    {
        tempExp.push_back(selectedExpansion);
    }

    output = tempExp;
}

void Grammar::parseOptionalGroupings(const vector<Expansion *> & expansions, vector<Expansion *> & returnExpansions)
{
    vector<Expansion *> tempExp;
    vector<Expansion *> exp = expansions;
    vector<Expansion *> children;
    unsigned short nestCount = 0;
    char startChar = '[';
    char endChar = ']';

    vector<Expansion *>::iterator expansionIterator = exp.begin();
    while(expansionIterator != exp.end())
    {
        if (typeid(*(*expansionIterator)) == typeid(UnparsedSection))
        {

            UnparsedSection * up = (UnparsedSection *) *expansionIterator;

            string childString;
            string outsideString;

            unsigned int stringSize = up->getSection().size();

            char cstr[stringSize+1];
            up->getSection().copy(cstr,stringSize);

            for (unsigned int i =0; i < stringSize; i++)
            {
                char c = cstr[i];
                if (c == startChar)
                {
                    nestCount++;
                    if (nestCount == 1)
                    {
                        if (outsideString.size() > 0)
                        {
                            UnparsedSection * u = new UnparsedSection(outsideString);
                            tempExp.push_back(u);
                        }
                        outsideString = "";
                        continue;
                    }
                }
                else if (c == endChar)
                {
                    nestCount--;
                    if (nestCount == 0)   // Transition to the end of the string
                    {
                        UnparsedSection * u = new UnparsedSection(childString);
                        children.push_back(u);
                        vector<Expansion *> parsedChildren;
                        parseOptionalGroupings(children, parsedChildren);
                        children.clear(); // Using children as next return value
                        parseUnaryOperators(parsedChildren, children);
                        shared_ptr<Expansion> child = shared_ptr<Expansion>(parseAlternativeSets(children));
                        OptionalGrouping *og = new OptionalGrouping(child);
                        tempExp.push_back(og);
                        childString = "";
                        children.clear();
                    }
                }

                if (nestCount >= 1)
                {
                    childString += c;
                }
                else if (c != endChar)
                {
                    outsideString += c;
                }
            }

            if (outsideString.size() > 0)
            {
                UnparsedSection * u = new UnparsedSection(outsideString);
                tempExp.push_back(u);
            }

            if (childString.size() > 0)
            {
                if (nestCount > 0)
                {
                    UnparsedSection * u = new UnparsedSection(childString);
                    children.push_back(u);
                }
                else
                {
                    UnparsedSection * u = new UnparsedSection(childString);
                    tempExp.push_back(u);
                }
            }
            delete *expansionIterator;
        }
        else
        {
            if (nestCount >= 1)   // Element is part of this grouping's children
            {
                children.push_back(*expansionIterator);
            }
            else
            {
                tempExp.push_back(*expansionIterator);
            }
        }
        expansionIterator++;
    }

    returnExpansions = tempExp;
}

void Grammar::parseRequiredGroupings(const vector<Expansion *> & expansions, vector<Expansion *> & returnExpansions)
{
    vector<Expansion *> tempExp;
    vector<Expansion *> exp = expansions;
    vector<Expansion *> children;
    unsigned short nestCount = 0;
    char startChar = '(';
    char endChar = ')';

    vector<Expansion *>::iterator expansionIterator = exp.begin();
    while(expansionIterator != exp.end())
    {
        if (typeid(*(*expansionIterator)) == typeid(UnparsedSection))
        {
            UnparsedSection * up = (UnparsedSection *) *expansionIterator;
            string childString;
            string outsideString;
            unsigned int stringSize = up->getSection().size();
            char cstr[stringSize+1];
            up->getSection().copy(cstr,stringSize);

            for (unsigned int i =0; i < stringSize; i++)
            {
                char c = cstr[i];
                if (c == startChar)
                {
                    nestCount++;
                    if (nestCount == 1)
                    {
                        if (outsideString.size() > 0)
                        {
                            UnparsedSection * u = new UnparsedSection(outsideString);
                            tempExp.push_back(u);
                        }
                        outsideString = "";
                        continue;
                    }
                }
                else if (c == endChar)
                {
                    nestCount--;
                    if (nestCount == 0)   // Transition to the end of the string
                    {
                        UnparsedSection * u = new UnparsedSection(childString);
                        children.push_back(u);
                        vector<Expansion *> parsedChildren;
                        parseRequiredGroupings(children, parsedChildren);
                        children.clear(); // Using children as next return value
                        parseOptionalGroupings(parsedChildren, children);
                        parsedChildren.clear(); // Using parsedChildren as next return value
                        parseUnaryOperators(children, parsedChildren);
                        children.clear(); // Using children as next return value
                        shared_ptr<Expansion> child = shared_ptr<Expansion>(parseAlternativeSets(parsedChildren));
                        RequiredGrouping *rg = new RequiredGrouping(child);
                        tempExp.push_back(rg);
                        childString = "";
                        children.clear();
                    }
                }

                if (nestCount >= 1)
                {
                    childString += c;
                }
                else if (c != endChar)
                {
                    outsideString += c;
                }
            }

            if (outsideString.size() > 0)
            {
                UnparsedSection * u = new UnparsedSection(outsideString);
                tempExp.push_back(u);
            }

            if (childString.size() > 0)
            {
                if (nestCount > 0)
                {
                    UnparsedSection * u = new UnparsedSection(childString);
                    children.push_back(u);
                }
                else
                {
                    UnparsedSection * u = new UnparsedSection(childString);
                    tempExp.push_back(u);
                }
            }

            delete *expansionIterator;
        }
        else
        {
            if (nestCount >= 1)   // Element is part of this grouping's children
            {
                children.push_back(*expansionIterator);
            }
            else
            {
                tempExp.push_back(*expansionIterator);
            }
        }
        expansionIterator++;
    }

    returnExpansions = tempExp;
}

void Grammar::parseRuleReferences(const vector<Expansion *> & expansions, vector<Expansion *> & returnExpansions)
{
    //Parse Rule References because they have next highest precedence
    //Pattern: "<"+TOKEN+">"
    vector<Expansion *> tempExp; // Temporary vector that will be copied into exp
    vector<Expansion *> exp = expansions;
    bool startSearch; // True = looking for a <
    bool endSearch; // True = looking for a >
    bool tokenSearch; // True = hoping that the next Expansion is a Token object containing the name of the rule that is being referenced
    Token * selectedToken; // Only set to null to avoid compiler warnings.

    bool iterationNeeded = true;
    while (iterationNeeded)
    {
        vector<Expansion *>::iterator expansionIterator = exp.begin();
        iterationNeeded = false;
        tempExp.clear();
        startSearch = true;
        endSearch = false;
        tokenSearch = false;
        selectedToken = nullptr;

        while(expansionIterator != exp.end())
        {
            if (startSearch)
            {
                if (typeid(*(*expansionIterator)) == typeid(UnparsedSection))
                {
                    UnparsedSection * up = (UnparsedSection *) *expansionIterator;
                    if (Grammar::stringEndsWith(up->getSection(), "<"))
                    {
                        startSearch = false;
                        tokenSearch = true;
                        //Found the < that starts the rule reference, so we need to remove it from the old UnparsedSection and add the new  UnparsedSection to the vector
                        string newUnprocessedText = up->getSection().substr(0, up->getSection().length() - 1); // Remove the last char, which should be the < symbol
                        UnparsedSection * u = new UnparsedSection(Grammar::trimString(newUnprocessedText));
                        tempExp.push_back(u); // Add the updated UnprocessedText section to the vector
                    }
                    else
                    {
                        tempExp.push_back(up); // UnparsedSection does not end in a < so it must not contain the start to a rule reference
                    }
                }
                else
                {
                    tempExp.push_back(*expansionIterator); // Not an UnparsedSection with text, continue on
                }
            }
            else if (endSearch)
            {
                if (typeid(*(*expansionIterator)) == typeid(UnparsedSection))
                {
                    UnparsedSection * up = (UnparsedSection *) *expansionIterator;
                    if (Grammar::stringStartsWith(up->getSection(), ">"))
                    {
                        endSearch = false;
                        startSearch = true;
                        RuleReference * rr = new RuleReference(selectedToken->getText());
                        tempExp.push_back(rr);
                        //Found the > that ends the rule reference, so we need to remove it from the old  UnparsedSection and add the new  UnparsedSection to the vector
                        string newUnprocessedText = up->getSection().replace(up->getSection().find(">"), 1, ""); // Remove the > token from the  UnparsedSection
                        UnparsedSection * u = new UnparsedSection(Grammar::trimString(newUnprocessedText));
                        tempExp.push_back(u);
                        iterationNeeded = true;
                    }
                    else
                    {
                        throw "Found start of rule reference, but did not find > immediately afterwards! found: " + (*expansionIterator)->getText();
                    }
                }
                else
                {
                    throw "Found start of rule reference, but did not find rule name immediately afterwards! found: " + (*expansionIterator)->getText();
                }
            }
            else if (tokenSearch)
            {
                if (typeid(*(*expansionIterator)) == typeid(Token))
                {
                    endSearch = true;
                    tokenSearch = false;
                    selectedToken = (Token *) *expansionIterator;
                }
                else
                {
                    throw "Found < character denoting rule reference, but did not find rule name immediately afterwards! found: " + (*expansionIterator)->getText();
                }
            }
            else
            {
                tempExp.push_back(*expansionIterator);
            }

            expansionIterator++;
        }
        exp = tempExp;
    }

    returnExpansions = exp;
    // return exp;
}

vector<Expansion *> Grammar::parseTokensFromString(string part)
{
    vector<Expansion *> exp;

    //Parse Tokens because they have the highest precedence
    string passed; // All characters that are not part of a token
    unsigned int position = 0;
    bool escapedMode; // If turned true, the next character will be added to the currentToken string without being evaluated
    bool quotedMode; // If turned true, all characters between quotes are added to the currentToken string
    char quoteType; // Which quote character to seek for to signify end of quote
    bool tokenMode = false; // If True, test and add the following characters to the currentToken string
    string currentToken;
    unsigned int stringLength = part.size();

    char * charArray = new char [stringLength];
    strcpy (charArray, part.c_str());
    char a; // This holds the current character that is being scanned
    string z = "";
    while (position < stringLength)
    {
        escapedMode = false;
        quotedMode = false;
        quoteType = '\'';
        tokenMode = false;
        currentToken = ""; // This holds the string of characters that are being scanned into one Token
        a = charArray[position];

        while (!tokenMode && position < stringLength)
        {
            a = charArray[position];
            if (!regex_match((z+a), Grammar::specialCharacterRegex))
            {
                UnparsedSection * up = new UnparsedSection();
                up->setSection(Grammar::trimString(passed));
                exp.push_back(up);
                passed = "";
                tokenMode = true;
                //DO NOT INCREMENT THE POSITION COUNTER, WE ARE LETTING THE NEXT LOOP EVALUATE THIS CHARACTER
            }
            else
            {
                passed += a;
                position++;
            }
        }

        if (!tokenMode)   // We reached the end of the string without finding a token, so add what we passed over
        {
            UnparsedSection * up = new UnparsedSection();
            up->setSection(Grammar::trimString(passed));
            exp.push_back(up);
            passed = "";
        }

        while (tokenMode && position < stringLength)
        {
            a = charArray[position]; // Retrieve the current char we are using
            if (escapedMode)   // escape mode ensures that the next character is not processed literally
            {
                escapedMode = false;
                currentToken += a;
                position++;
            }
            else
            {
                if (a == '\\')   // Test to see if char triggers escape mode
                {
                    escapedMode = true;
                    position++;
                }
                else if (quotedMode)     // Token is either like: "blarg" or: 'blarg'
                {
                    if (a == quoteType)
                    {
                        quotedMode = false;
                        tokenMode = false;
                        currentToken += quoteType; // The last character is a part of the token (Either ' or " )
                        position++; // Last character was added to the token, so it was processed, increment the position counter
                        //Entire token has now been scanned into currentToken
                        Token * t = new Token(currentToken);
                        exp.push_back(t);
                        currentToken = "";
                    }
                    else     // Characters within the quotes
                    {
                        currentToken += a;
                        position++;
                    }
                }
                else if (a == '\"')
                {
                    quotedMode = true;
                    quoteType = '\"';
                    currentToken += a;
                    position++;
                }
                else if (a == '\'')
                {
                    quotedMode = true;
                    quoteType = '\'';
                    currentToken += a;
                    position++;
                }
                else if (regex_match((z+a), Grammar::specialCharacterRegex))     // Check to see if char matches special characters
                {
                    tokenMode = false;
                    //Entire token has now been scanned into currentToken
                    Token * t = new Token(currentToken);
                    exp.push_back(t);
                    currentToken = "";
                    passed = a;
                    position++;
                }
                else
                {
                    currentToken += a;
                    position++;
                }
            }
        }
        if (tokenMode)   // Reached end of string before end of token
        {
            Token * t = new Token(currentToken);
            exp.push_back(t);
            currentToken = "";
        }
    }

    if (!tokenMode)   // We reached the end of the string without finding a token, so add what we passed over
    {
        UnparsedSection * up = new UnparsedSection();
        up->setSection(Grammar::trimString(passed));
        exp.push_back(up);
    }

    //Everything that can be Tokenized has been tokenized, so remove all of the whitespace as it serves no function now
    vector<Expansion *>::iterator expansionIterator = exp.begin();
    vector<Expansion *> tempExp;
    while(expansionIterator != exp.end())
    {
        if (typeid(*(*expansionIterator)) == typeid(UnparsedSection))
        {
            UnparsedSection * up = (UnparsedSection *) *expansionIterator;
            string test = regex_replace(up->getSection(), regex(" "), "");
            if (test.length() != 0)
            {
                UnparsedSection * u = new UnparsedSection(test);
                tempExp.push_back(u);
            }
        }
        else
        {
            tempExp.push_back(*expansionIterator);
        }
        expansionIterator++;
    }

    exp = tempExp;

    return exp;
}

Expansion * Grammar::parseAlternativeSets(vector<Expansion *> & exp)
{
    vector<Expansion *> tempExp;
    //Remove all leftover UnparsedSections
    vector<Expansion *>::iterator expansionIterator;

    for (expansionIterator = exp.begin(); expansionIterator != exp.end(); expansionIterator++)
    {
        if (typeid(*(*expansionIterator)) == typeid(UnparsedSection))
        {
            UnparsedSection & up = *((UnparsedSection *) (*expansionIterator));
            if (up.getSection() == "" || up.getSection() == " ")
            {
                delete *expansionIterator;
                // Don't copy the blank section over to the Expansion vector
            }
            else
            {
                up.setSection(Grammar::trimString(up.getSection()));
                tempExp.push_back(&up);
            }
        }
        else
        {
            tempExp.push_back(*expansionIterator);
        }
    }

    Sequence * currentSequence = new Sequence(); // CREATED ON THE FREE STORE!
    AlternativeSet * aset = new AlternativeSet(); // CREATED ON THE FREE STORE!
    expansionIterator = tempExp.begin();

    while (expansionIterator != tempExp.end())
    {
        if (typeid(*(*expansionIterator)) == typeid(UnparsedSection))
        {
            UnparsedSection * up = (UnparsedSection *) *expansionIterator;
            if (Grammar::stringContains(up->getSection(), "|"))
            {

                Expansion * a = currentSequence;
                if(currentSequence->childCount() == 1)
                {
                    Expansion * e = currentSequence->getChild()->clone();
                    a = e;
                    delete currentSequence;
                }


                aset->addChild(shared_ptr<Expansion>(a));
                currentSequence = new Sequence();
            }
            else
            {
                currentSequence->addChild(shared_ptr<Expansion>(up));
            }
        }
        else
        {
            currentSequence->addChild(shared_ptr<Expansion>(*expansionIterator));
        }
        expansionIterator++;
    }

    Expansion * output;
    if (aset->childCount() > 0)
    {
        Expansion * a = currentSequence;
        if(currentSequence->childCount() == 1)
        {
            Expansion * e = currentSequence->getChild()->clone();
            a = e;
            delete currentSequence;
        }
        aset->addChild(shared_ptr<Expansion>(a));
        output = aset;
    }
    else
    {
        delete aset; // aset has no children yet, and we are not returning it. so it must be deleted, and deleting it won't result in any dangling pointers

        if(currentSequence->childCount() == 1)
        {
            Expansion * e = currentSequence->getChild()->clone();
            delete currentSequence;
            output = e;
        }
        else
        {
            output = currentSequence;
        }
    }

    return output;
}

/**
  * Returns a pointer to a Rule object that has the specified name. Returns nullptr if not rule can be found!
  * \param [in] ruleName
  * \return shared_ptr<Rule>
  * \return nullptr if no rule can be found
  */
shared_ptr<Rule> Grammar::getRule(string ruleName)
{
    for(shared_ptr<Rule> r : rules)
    {
        if(r->getRuleName() == ruleName)
        {
            return r;
        }
    }
    return nullptr;
}

/** Walks through all of the expansions in every rule. Calls the callback function for each expansion it walks across.
  * \param callback A void returning function that expects a pointer to an Expansion for its args. The expansion pointer is the expansion that was encountered
  *
  *
  */
void Grammar::walkGrammar(void (* callback)(Expansion *)) {
    for(shared_ptr<Rule> r : rules) {
        walkExpansion(r->getRuleExpansion().get(), callback);
    }
}

/// Walks through the given expansion and all of its children. Calls the callback function for each expansion it walks across.
void Grammar::walkExpansion(Expansion * e, void (* callback)(Expansion *)) {
    callback(e);
    if(e->hasChild()) {
        for(unsigned int i = 0; i < e->childCount(); i++) {
            Grammar::walkExpansion(e->getChild(i).get(), callback);
        }
    }
}

/**
  * Matches the array of word strings against the specified Expansion. Mainly used internally. Use Grammar::matchedRule() for testing for matches.
  * \param [in] e The Expansion being tested against
  * \param [in] words[] array of strings that are being matched against the Expansion
  * \param [in] wordCount Number of words that are being matched (usually is the the length of words[])
  * \param [in] wordPosition Index of the word to start matching at
  * \return vector<shared_ptr<MatchInfo>> - std::vector of MatchInfo objects
  */
vector<shared_ptr<MatchInfo>> Grammar::getMatchingExpansions(shared_ptr<Expansion> e, string words[], unsigned int wordCount, unsigned int wordPosition)
{
    vector<shared_ptr<MatchInfo>> matchvector;

    if ((e.get())->getType() == TOKEN)
    {
        Token * t = (Token *) e.get();
        if (t->getText() == (words[wordPosition]))
        {
            string matchedPart = words[wordPosition];
            matchvector.push_back(shared_ptr<MatchInfo>(new MatchInfo(shared_ptr<Expansion>(e), words[wordPosition])));
        }
        else
        {
            // No match
        }
    }
    else if ((e.get())->getType() == RULE_REFERENCE)
    {
        RuleReference * ref = (RuleReference *) e.get();

        Rule * rule = getRule(ref->getRuleName()).get(); // Try to get the rule
        if(rule)
        {
            vector<shared_ptr<MatchInfo>> m1 = (getMatchingExpansions(rule->getRuleExpansion(), words, wordCount, wordPosition));
            if (m1.size() != 0)
            {
                matchvector.push_back(shared_ptr<MatchInfo>(new MatchInfo(shared_ptr<Expansion>(e), ""))); // Need to mark that the rule was matched!
                matchvector.insert(matchvector.end(), m1.begin(), m1.end());
            }
        }
    }
    else if ((e.get())->getType() == OPTIONAL_GROUPING)
    {
        OptionalGrouping * og = (OptionalGrouping *) e.get();
        vector<shared_ptr<MatchInfo>> m1 = getMatchingExpansions(og->getChild(), words, wordCount, wordPosition);
        if (m1.size() == 0)
        {
            // Optional, so it can match. Used for sequences
        }
        else
        {
            //Matches
            matchvector.push_back(shared_ptr<MatchInfo>(new MatchInfo(shared_ptr<Expansion>(e), "")));
            vector<shared_ptr<MatchInfo>> moreMatches = getMatchingExpansions(og->getChild(), words, wordCount, wordPosition);
            matchvector.insert(matchvector.end(), moreMatches.begin(), moreMatches.end());
        }
    }
    else if ((e.get())->getType() == REQUIRED_GROUPING)
    {
        RequiredGrouping * rg = (RequiredGrouping *) e.get();
        vector<shared_ptr<MatchInfo>> m1 = getMatchingExpansions(rg->getChild(), words, wordCount, wordPosition);

        if (m1.size() != 0)
        {
            matchvector.push_back(shared_ptr<MatchInfo>(new MatchInfo(shared_ptr<Expansion>(e), "")));
            matchvector.insert(matchvector.end(), m1.begin(), m1.end());
        }
    }
    else if (e.get()->getType() == TAG)
    {
        Tag * t = (Tag *) e.get();
        vector<shared_ptr<MatchInfo>> m1 = getMatchingExpansions(t->getChild(), words, wordCount, wordPosition);

        if (m1.size() != 0)
        {
            matchvector.push_back(shared_ptr<MatchInfo>(new MatchInfo(shared_ptr<Expansion>(e), "")));
            matchvector.insert(matchvector.end(), m1.begin(), m1.end());
        }
    }
    else if ((e.get())->getType() == ALTERNATE_SET)
    {
        AlternativeSet * as = (AlternativeSet *) e.get();
        for (shared_ptr<Expansion> x : as->getChildren())
        {
            vector<shared_ptr<MatchInfo>> m1 = getMatchingExpansions(x, words, wordCount, wordPosition);

            if (m1.size() == 0 && (typeid(*x) == typeid(KleeneStar) || typeid(*x) == typeid(OptionalGrouping)))   // Stupid OptionalGrouping
            {
                continue;
            }

            if (m1.size() != 0)
            {
                matchvector.push_back(shared_ptr<MatchInfo>(new MatchInfo(shared_ptr<Expansion>(e), "")));
                matchvector.insert(matchvector.end(), m1.begin(), m1.end()); // Found a match! Add it to the vector
                break;
            }
        }
    }
    else if ((e.get())->getType() == SEQUENCE)
    {
        Sequence * seq = (Sequence *) e.get();
        vector<shared_ptr<MatchInfo>> localMatchvector;
        vector<shared_ptr<Expansion>> expansions = seq->getChildren();
        int matchedCount = 0;

        for (shared_ptr<Expansion> x : expansions)
        {
            vector<shared_ptr<MatchInfo>> m1 = getMatchingExpansions(x, words, wordCount, wordPosition);
            if (m1.size() == 0 && (x->getType() == KLEENE_STAR || x->getType() == OPTIONAL_GROUPING))   // Stupid OptionalGrouping
            {
                matchedCount++; // Still counts a match
                continue;
            }

            if (m1.size() != 0)
            {
                matchedCount++;
                for (shared_ptr<MatchInfo> localMatch : m1)
                {
                    if(localMatch->getMatchingSection() != "")
                    {
                        wordPosition += Grammar::splitString(localMatch->getMatchingSection(), " ").size();
                    }
                }
                localMatchvector.insert(localMatchvector.end(), m1.begin(), m1.end()); // Found a match! Add it to the vector
            }
            else   // Doesn't match! Sequence aborted.
            {
                localMatchvector.clear();
                break;
            }

            if (wordPosition > wordCount - 1)   // Sequence is longer than provided words! Abort!
            {
                break;
            }
        }

        if (matchedCount != seq->childCount())   // Not all of the required matches were met!
        {
            localMatchvector.clear();
        }

        if (localMatchvector.size() != 0)
        {
            matchvector.push_back(shared_ptr<MatchInfo>(new MatchInfo(shared_ptr<Expansion>(e), "")));
            matchvector.insert(matchvector.end(), localMatchvector.begin(), localMatchvector.end());
        }
    }
    else if ((e.get()->getType()) == KLEENE_STAR)
    {
        KleeneStar * ks = (KleeneStar *) e.get();
        bool done = false;
        vector<shared_ptr<MatchInfo>> m1;
        matchvector.push_back(shared_ptr<MatchInfo>(new MatchInfo(shared_ptr<Expansion>(e), "")));
        while(!done)
        {
            if (wordPosition > wordCount - 1)
            {
                break;
            }
            m1 = getMatchingExpansions(ks->getChild(), words, wordCount, wordPosition);
            if (m1.size() == 0)
            {
                // No matches
                done = true;
            }
            else
            {
                //Matches
                for (shared_ptr<MatchInfo> mi2 : m1)
                {
                    if(mi2->getMatchingSection() != "")
                    {
                        wordPosition += Grammar::splitString(mi2->getMatchingSection(), " ").size();
                    }
                }
                matchvector.insert(matchvector.end(), m1.begin(), m1.end());
                matchvector.push_back(shared_ptr<MatchInfo>(new MatchInfo(shared_ptr<Expansion>(e), "")));
            }
        }
    }
    else if ((e.get())->getType() == PLUS_OPERATOR)
    {
        PlusOperator * po = (PlusOperator *) e.get();
        bool done = false;
        vector<shared_ptr<MatchInfo>> m1;
        while(!done)
        {
            if (wordPosition > wordCount-1)
            {
                break;
            }
            m1 = getMatchingExpansions(po->getChild(), words, wordCount, wordPosition);
            if (m1.size() == 0)
            {
                // No matches
                done = true;
            }
            else
            {
                //Matches
                matchvector.push_back(shared_ptr<MatchInfo>(new MatchInfo(shared_ptr<Expansion>(e), "")));
                for (shared_ptr<MatchInfo> mi2 : m1)
                {
                    if(mi2->getMatchingSection() != "")
                    {
                        wordPosition += Grammar::splitString(mi2->getMatchingSection(), " ").size();
                    }
                }
                matchvector.insert(matchvector.end(), m1.begin(), m1.end());
            }
        }
    }

    return matchvector;
}


/**
  * Matches a string of words (test) against the specified Rule.
  * If the test string does not match the Rule, will return a vector with a length/size of 0.
  * \param [in] rule Rule being matched against
  * \param [in] test std::string being matched
  * \return vector<shared_ptr<MatchInfo>> - vector of MatchInfo objects. Can have a size of 0 if test string does not match.
  */
vector<shared_ptr<MatchInfo>> Grammar::matchesRule(shared_ptr<Rule> rule, string test) {
    vector<string> words = Grammar::splitString(test, " ");
    string* wordArray = &words[0];
    vector<shared_ptr<MatchInfo>> m1 = getMatchingExpansions(rule->getRuleExpansion(), wordArray, words.size(), 0);
    unsigned int matchCount = 0;
    for (shared_ptr<MatchInfo> mi2 : m1) {
        if (mi2->getMatchingSection() != "") {
            matchCount++;
        }
    }
    if(matchCount != words.size()) { // Must match all the words!
        m1.clear();
    }

    return m1;
}

/**
  * Overloading convenience function for vector<shared_ptr<MatchInfo>> Grammar::matchesRule(shared_ptr<Rule> rule, string test) that accepts a string for the rule name.
  * \param [in] ruleName Name of the Rule to be matched against
  * \param [in] test string that will be matched against the Rule
  * \return vector<shared_ptr<MatchInfo>> - see vector<shared_ptr<MatchInfo>> Grammar::matchesRule(shared_ptr<Rule> rule, string test)
  */
vector<shared_ptr<MatchInfo>> Grammar::matchesRule(string ruleName, string test) {
    shared_ptr<Rule> r = getRule(ruleName);
    if(!r) { // Check to make sure rule exists
        vector<shared_ptr<MatchInfo>> m;
        return m;
    }
    return matchesRule(r, test);
}

vector<string> Grammar::getMatchingTags(vector<shared_ptr<MatchInfo>> matchInfo) {
    vector<string> matchedTags;
    for(shared_ptr<MatchInfo> m : matchInfo) {
        if(typeid(*(m->getExpansion().get())) == typeid(Tag)) {
            Tag * t = (Tag *) m->getExpansion().get();
            vector<string> s = t->getTags();
            matchedTags.insert(matchedTags.end(), s.begin(), s.end());
        }
    }
    return matchedTags;
}

/**
  * Static helper function that replaces the first occurrence of regex re in string s with the replacement string
  * \param [in] s string that is being modified
  * \param [in] re A string representing a C regex that will be matches against string s
  * \param [in] replacement A string that will replace the first match of re against string s
  * \return string The modified string with the first occurrence of re replaced with replacement
  */
string Grammar::replaceFirst(string s, string re, string replacement)
{
    regex reg (re);
    return regex_replace(s, reg, replacement, regex_constants::format_first_only);
}

/**
  * Static helper function that replaces all occurrences of regex re in string s with the replacement string
  * \param [in] s string that is being modified
  * \param [in] re A string representing a C regex that will be matches against string s
  * \param [in] replacement A string that will replace the first match of re against string s
  * \return string The modified string with all occurrences of re replaced with replacement
  */
string Grammar::replaceAll(string s, string re, string replacement)
{
    regex reg (re);
    return regex_replace(s, reg, replacement);
}

///Compliments to: https://stackoverflow.com/questions/16749069/c-split-string-by-regex for the below code
vector<string> Grammar::splitString(const string & s, string rgx_str)
{
    vector<string> elems;

    regex rgx (rgx_str);

    sregex_token_iterator iter(s.begin(), s.end(), rgx, -1);
    sregex_token_iterator end;

    while (iter != end)
    {
        elems.push_back(*iter);
        ++iter;
    }

    return elems;
}

bool Grammar::stringContains(string part, string search)
{
    size_t p = part.find(search);
    return p != string::npos;
}

bool Grammar::stringStartsWith(string s, string test)
{
    return s.find(Grammar::trimString(test)) == 0;
}

bool Grammar::stringEndsWith(string s, string test)
{
    return (s.find(Grammar::trimString(test)) == s.length() - test.length()) && s.find(test) != string::npos;
}

///Thanks for this trimming function: https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring

// trim from start
inline std::string &Grammar::ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
            std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
inline std::string &Grammar::rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}


inline string Grammar::trimString(string input)
{
    return ltrim(rtrim(input));
}
