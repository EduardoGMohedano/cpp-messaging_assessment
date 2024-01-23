<img src="./honeywell.png" alt="Honeywell Logo" />

## Hello #FutureShaper
I am glad that you passed the first stages of the interview process 🎉🥳. Now is the time to show us what you got! 

# Problem description:
Below you can find implementation for classes *Recipient* and *Network*. Both inherit the *Message* class.
```cpp
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
```
Implement classes *Message* and *MessageFactory* based on:

	- Class *Message* is required to store a text value of type *std::string* and provide a public getter *const string& get_text()* to return it. It should implement the *<* operator that will be used in *recipient.fix_order()* method to reorder received messages. You can also implement any other method/class/instance/variables if you want.
	- Class *MessageFactory* is required to have an empty constructor and implement a method *Message create_message(const string& text)*. You can also implement any other method/class/instance/variables if you want.

Your will have to create objects *message_factory* and *recipient* of type *MessageFactory* and * Recipient*, respectively. Then, the program reads messages from standart input and use the Network class to simulate sending messages to the *recipient* class. 
The *Network* class randomly shuffles the passes messages and passes them to the *recipient* using *recipient.receive(const Message&)* method.
When all the messages are received, you will use *recipient.fix_order()* to get the vector reordered and then *recipient.print_messages* to print to the standard output all the messages contained in the *std::vector*.

# Example
Consider the following input example:
	Hello!
	Hello John!
	Are you up to hang out tonight?
	I am totally down!

Let's say the messages are received in the following order (simulated by *random_shuffle*):
	Are you up to hang out tonight?
	Hello!
	I am totally down!
	Hello John!
	
The output should be the exact smae as the input after we got the meesages reorder by *fix_order()*
	Hello!
	Hello John!
	Are you up to hang out tonight?
	I am totally down!

# Constraints

- There will be at most 10 lines in the input.
- Each line will contain at most 20 characters.

# Submission
- Fork this repository to your GitHub account.
- Add your work.
- Test your changes thoroughly.
- Commit your changes and push them to your forked repository.
- Share the link to your forked repository with the interviewer.

Good Luck!