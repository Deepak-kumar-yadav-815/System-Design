#include<iostream>
#include<vector>
#include<string.h>
#include<fstream>

using namespace std;

class DocumentEditor {
    private:
        vector<string> DocumentElements;
        string renderedDocument;
    public:
        void addText(string text){
            DocumentElements.push_back(text);
        }
        void addImage(string imagepath){
            DocumentElements.push_back(imagepath);
        }
        string renderDocument(){
            if(renderedDocument.empty()) {
            string result;
            for (auto element : DocumentElements) {
                if (element.size() > 4 && (element.substr(element.size() - 4) == ".jpg" ||
                 element.substr(element.size() - 4) == ".png")) {
                    result += "[Image: " + element + "]" + "\n";
                } else {
                    result += element + "\n";
                }
            }
                renderedDocument = result;
            }
            return renderedDocument;
        }
        void SaveToFile(){
            ofstream file("document.txt");
            if(file.is_open()){
                file << renderDocument();
                file.close();
                cout<<"Document saved to document.txt"<<endl;
            } else {
                cout<<"Error: Unable to open file for writing. "<<endl;
            }
        }
};
int main(){
    DocumentEditor editor;
    editor.addText("Hello, world");
    editor.addImage("picture.jpg");
    editor.addText("This is a document editor.");

    cout<<editor.renderDocument()<<endl;
    
    editor.SaveToFile();

    return 0;
}