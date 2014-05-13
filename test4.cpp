#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "rapidxml-1.13/rapidxml.hpp"

using namespace rapidxml;
using namespace std;

int main()
{
    //	cout << "Parsing a xml file..." << endl;
    xml_document<> doc;
    xml_node<> *root_node, *subNode, *sub1Node;
    // Read the xml file into a vector
    ifstream theFile ("test.html");
    vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
    buffer.push_back('\0');
    // Parse the buffer using the xml file parsing library into doc
    doc.parse<0>(&buffer[0]);

    root_node = doc.first_node();

    cout << "\n The first node is :- " << root_node->name() << "\n";

    subNode = root_node->first_node();

    for( ; subNode ; subNode = subNode->next_sibling())
    {

        cout << "\t" << subNode->name() <<", " << subNode->value() << ", ";
//        cout << subNode->first_attribute("attribute")->value();
        cout << "\n";

        //        cout << "\t The next nested node is :- " << subNode->name() << "\n";
        //        cout << "\t This node has the value :- " << subNode->value() << "\n";
        //        if(subNode->first_node()){
        //            sub1Node = subNode->first_node();
        //            cout << "\t\t A nested node is :- " << sub1Node->name() << "\n";
        //        }

        //        cout << "\t The value of the attribute of name attribute is :- " << subNode->first_attribute("atribute") << "\n";

    }
}
