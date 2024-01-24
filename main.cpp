
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Message{
public:
    Message(){}
    Message(string msg,int order): text_value(msg), arrived_order(order){};

    bool operator<(const Message& other){
        return arrived_order < other.arrived_order;
    }

    const string& get_text(){
        return text_value;
    }

private:
    string text_value{};
    int arrived_order;
};

class MessageFactory{
public:
    MessageFactory(){}

    Message create_message(const string& text){
        return Message(text,order++);
    }
private:
    int order = 0;
};

class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
    void print_messages_unordered() {
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
    // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());         
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};


int main(){
    string line;
    vector<Message> input{};

    // Read lines until end-of-file is encountered (Press ctrl+d to stop reading std input)
    cout<<"Start typing your messages: "<<endl;
    MessageFactory msg_factory;
    Message tmp;
    while (getline(cin, line)) {
        tmp = msg_factory.create_message(line);
        input.push_back(tmp);
    }

    cout << "\nThe lines you entered as user are: " << line << endl; 
    for(auto msg: input)
        cout<<msg.get_text()<<endl;

    Recipient recipient;
    Network::send_messages(input,recipient);

    cout << "\nThe lines disoreded are:" << line << endl; 
    recipient.print_messages_unordered();
    
    cout << "\nThe lines in order are: "<<endl;
    recipient.print_messages();
    return 0;
}