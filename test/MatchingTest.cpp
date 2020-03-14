#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "grammar.h"

using namespace std;

/**
  * \file MatchingTest.cpp
  * A simple program that shows how to parse a JSGF string to create a new Grammar object and then match an input string against the grammar's rules.
  * Takes a file given via the command line, parses it, and then matches an input string taken from stdin to match against it.
  * Can print the name of the rule it matches, or the tags that it matches. This can be specified through the command line options.
  */

void printUsage() {
	cout << "JSGF Matching" << endl << \
		"Usage:" << endl << \
		"\tjsgfmatch -f GRAMMAR_FILE (-r | -t)" << endl << endl << \
		"\t-f\tSpecifies the path to the grammar file to parse." << endl << \
		"\t-r\tSpecifies to print out the public rule that the input matches, if any." << endl << \
		"\t-t\tSpecifies to print out the tag(s) that the input matches, if any." << endl << endl <<\
		"When printing matching tags, if there are multiple tags, they will be printed out separated by commas in order of appearance. The tags will not include the { } characters." << endl << endl << \
		"Author: Tyler Sengia <ExpandingDev> (tylersengia@gmail.com)" << endl;
}

int main(int argc, char *argv[])
{
	// Options specified by the user via command line
	bool printRule = false;
	bool printTags = false;
	bool grammarSet = false;
	char * grammarPath;

	//Parse command line options
	int opt;
	while((opt = getopt(argc, argv, "rtf:")) != -1) {
		switch(opt) {
			case 'r':
				printRule = true;
			break;
			case 't':
				printTags = true;
			break;
			case 'f':
				grammarSet = true;
				grammarPath = optarg;
			break;
			default:
				cerr << "Unrecognized command option" << endl;
				printUsage();
				return -1;
			break;
		}
	}

	if(!grammarSet) {
		cerr << "Please specify the grammar file to parse!" << endl;
		printUsage();
		return -1;
	}

	if (!printRule && !printTags) {
		cerr << "Please specify to print either tags (-t) or rules (-r)!" << endl;
		printUsage();
		return -1;
	}

	Grammar g;
	std::ifstream inputFile;
	inputFile.open(grammarPath);
	if(inputFile.good()) {
		Grammar::parseGrammar(inputFile, g);
	}
	else {
		cerr << "Failed to open the specified grammar file!" << endl;
		return -1;
	}

	string test = "";
	getline(cin, test);

//	MatchResult r = g.match(test);

	//Print out the public rule the input matches
	if(printRule) {
		string s = g.getMatchingPublicRule(test);
		if(s != "") {
			cout << "Match: " << s << endl;
		}
	}

	//Print out the matching tags, separatd by commas
	if(printTags) {
		vector<string> tags = g.getMatchingTags(test);
		if(tags.size() > 0) {
			unsigned short i = 0;
			for(; i < tags.size()-1; i++) {
				cout << tags[i] << ",";
			}
			if(i == tags.size()-1) {
				cout << tags[i];
			}
		}
	}

	return 0;
}
