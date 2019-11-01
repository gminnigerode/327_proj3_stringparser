/*
 * StringParserClass.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */

#include <string>
#include <string.h>
#include <iostream>
#include "../327_proj3_test/includes/StringParserClass.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;
using namespace KP_StringParserClass;

StringParserClass::StringParserClass(){
	pStartTag = NULL;
	pEndTag = NULL;
	areTagsSet = false;
}

StringParserClass::~StringParserClass(){
	cleanup();
}

int StringParserClass::setTags(const char *pStart, const char *pEnd){
	if(pStart == NULL || pEnd== NULL){
		return ERROR_TAGS_NULL;
	}
	int startLen = strlen(pStart);
	pStartTag = new char[startLen +1];
	strncpy(pStartTag,pStart,startLen);
	int endLen = strlen(pEnd);
	pEndTag = new char[endLen +1];
	strncpy(pEndTag,pEnd,endLen);
	areTagsSet = true;
	return SUCCESS;
}

int StringParserClass::getDataBetweenTags(char *pDataToSearchThru, std::vector<std::string> &myVector){
	//TODO Implement
	if(!areTagsSet || pStartTag == NULL || pEndTag == NULL){
		return ERROR_TAGS_NULL;
	}
	if(pDataToSearchThru == NULL){
		return ERROR_DATA_NULL;
	}
	for (int i = 0; i<(strlen(pDataToSearchThru)-strlen(pStartTag)); i++){
		if(*(pDataToSearchThru+i) == *(pStartTag)){
			if(strncmp(pDataToSearchThru+i,pStartTag,strlen(pStartTag)) == 0){
				//Found start tag
				bool notAtEnd = true;
				while(notAtEnd){
					if(strncmp(pDataToSearchThru+i,pEndTag,strlen(pEndTag)) == 0){
						notAtEnd = false;
					}
					else{
						myVector.emplace_back(*pDataToSearchThru+i);
						i++;
					}
				}
			}
		}
	}
	return SUCCESS;
}

void StringParserClass::cleanup(){
	delete[] pStartTag;
	delete[] pEndTag;
	delete areTagsSet;
}

int StringParserClass::findTag(char *pTagToLookFor, char *&pStart, char *&pEnd){
	//TODO Implement
	if(!areTagsSet || pStartTag == NULL || pEndTag == NULL){
		return ERROR_TAGS_NULL;
	}
	for (int i = 0; i < strlen(pTagToLookFor); i++){
			if(*(pTagToLookFor+i) == *(pStartTag)){
				if(strncmp(pTagToLookFor+i,pStartTag,strlen(pStartTag)) == 0){
					//Found start tag

					return SUCCESS;
				}
			}
	}
	return FAIL;
}

