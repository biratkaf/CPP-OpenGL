#include <iostream>
#include <string> 
using namespace std;

int main()
{
    string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
    string key{ "phqgiumeaylnofdxjkrcvstzwbQPWOEIRUTYALSKDJFHGZMXNCBV" };

    string secret_message{};
    cout << "Enter your secret message : ";
    getline(cin, secret_message);

    string encrypted_message{};

    for (char c : secret_message)
    {
        size_t position = alphabet.find(c);
        if (position != string::npos)
        {
            char new_char = key.at(position);
            encrypted_message += new_char;
        }
        else {
            encrypted_message += c;

        }
    }
    cout << "Encypted message " << encrypted_message << endl;

    string dycrpted_message{};
    for (char c : encrypted_message) {
        size_t new_position = key.find(c);
        if (new_position != string::npos) {
            char dcr_char = alphabet.at(new_position);
            dycrpted_message += dcr_char;
        }
        else {
            dycrpted_message += c;

        }
    }

    cout << "Dycrypted Message " << dycrpted_message << endl;


    return 0;
}