#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string encryption(string message, string key)
{
    string encrypted_text;
    int t = 0;
    for (int i = 0; i < message.length(); i++)
    {
        encrypted_text += wchar_t(int(message[i]) + int(key[t]) - int('0'));
        t++;
        if (t == key.length())
        {
            t = 0;
        }
    }
    return encrypted_text;
}

string decryption(string encrypted_text, string key)
{
    int t = 0;
    string decrypted_text;
    for (int i = 0; i < encrypted_text.length(); i++)
    {
        decrypted_text += wchar_t(int(encrypted_text[i]) - int(key[t]) + int('0'));
        t++;
        if (t == key.length())
        {
            t = 0;
        }
    }
    return decrypted_text;
}

int check(string fake_key, string encrypted_text, string clue)
{
    string fake_decrypted_text = decryption(encrypted_text, fake_key);
    if (!(fake_decrypted_text.find(clue) == std::string::npos))
    {
        cout << "decrypted text: " << fake_decrypted_text << endl;
        return 1;
    }
    return 0;
}

int foo(string str, string encrypted_text, string clue)
{
    int LAST = str.length() - 1;
    int flag = 1;

    //cout << str << '\n';
    while (str[0] != '0')
    {
        for (int i = 0; i < 10; i++)
        {
            str[LAST] = char(int(str[LAST] - '0') + 1 + '0');
            if (str[LAST] == ':')
            {
                str[LAST] = '0';
                str[LAST - 1] = char(int(str[LAST - 1] - '0') + 1 + '0');
            }

            int k = check(str, encrypted_text, clue);
            if (k == 1)
            {
                bool flag3 = true;
                while (flag3)
                {
                    cout << "possible key: " << str << endl;
                    cout << "would you like to guess the key? Y/N ";
                    char ans;
                    cin >> ans;
                    cout << endl;
                    if (ans == 'Y' || ans == 'y')
                    {
                        string possible_key;
                        cout << "enter possible key" << endl;
                        cin >> possible_key;
                        cout << decryption(encrypted_text, possible_key) << endl;
                        cout << "does this text make any sense? Y/N ";
                        char ans1;
                        cin >> ans1;
                        if (ans1 == 'Y' || ans1 == 'y')
                        {
                            cout << "hacked!" << endl;
                            return 1;
                        }
                        else
                        {
                            cout << "too bad\n";
                            cout << "would you like to try again? Y/N" << endl;
                            char ans3;
                            cin >> ans3;
                            if (ans3 == 'Y' || ans3 == 'y')
                            {
                                continue;
                            }
                            else
                            {
                                cout << "would you like for programm to try to find another key? Y/N " << endl;
                                char ans4;
                                cin >> ans4;
                                if (ans4 == 'Y' || ans4 == 'y')
                                {
                                    flag3 = false;
                                    continue;
                                }
                                else
                                {
                                    return 0;
                                }
                            }

                        }
                    }
                    else
                    {
                        cout << "too bad\n";
                        cout << "would you like for programm to try to find another key? Y/N " << endl;
                        char ans4;
                        cin >> ans4;
                        if (ans4 == 'Y' || ans4 == 'y')
                        {
                            flag3 = false;
                            continue;
                        }
                        else
                        {
                            return 0;
                        }
                    }
                    flag3 = false;
                }

            }

            //cout << str << '\t';
            if (str[LAST] == '9' && str[LAST - 1] == '9')
            {
                int ctr = 0;
                int ctr1 = LAST;
                while (str[ctr1] == '9')
                {
                    str[ctr1] = '0';
                    ctr++;
                    ctr1--;
                    if (ctr1 < 0)
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 0)
                {
                    return -1;
                }
                str[ctr1] = char(int(str[ctr1] - '0') + 1 + '0');
                if (str[LAST] == ':')
                {
                    str[LAST] = '0';
                    str[LAST - 1] = char(int(str[LAST - 1] - '0') + 1 + '0');
                }

                k = check(str, encrypted_text, clue);
                if (k == 1)
                {
                    //exit = false;
                    cout << "possible key: " << str << endl;
                    bool flag3 = true;
                    while (flag3)
                    {
                        cout << "possible key: " << str << endl;
                        cout << "would you like to guess the key? Y/N ";
                        char ans;
                        cin >> ans;
                        cout << endl;
                        if (ans == 'Y' || ans == 'y')
                        {
                            string possible_key;
                            cout << "enter possible key" << endl;
                            cin >> possible_key;
                            cout << decryption(encrypted_text, possible_key) << endl;
                            cout << "does this text make any sense? Y/N ";
                            char ans1;
                            cin >> ans1;
                            if (ans1 == 'Y' || ans1 == 'y')
                            {
                                cout << "hacked!" << endl;
                                return 1;
                            }
                            else
                            {
                                cout << "too bad\n";
                                cout << "would you like to try again? Y/N" << endl;
                                char ans3;
                                cin >> ans3;
                                if (ans3 == 'Y' || ans3 == 'y')
                                {
                                    continue;
                                }
                                else
                                {
                                    cout << "would you like for programm to try to find another key? Y/N " << endl;
                                    char ans4;
                                    cin >> ans4;
                                    if (ans4 == 'Y' || ans4 == 'y')
                                    {
                                        flag3 = false;
                                        continue;
                                    }
                                    else
                                    {
                                        return 0;
                                    }
                                }

                            }
                        }
                        else
                        {
                            cout << "too bad\n";
                            cout << "would you like for programm to try to find another key? Y/N " << endl;
                            char ans4;
                            cin >> ans4;
                            if (ans4 == 'Y' || ans4 == 'y')
                            {
                                flag3 = false;
                                continue;
                            }
                            else
                            {
                                return 0;
                            }
                        }
                        flag3 = false;
                    }
                    //cout << str << '\t';
                }
                if (str[LAST] == ':')
                {
                    str[LAST] = '0';
                    str[LAST - 1] = char(int(str[LAST - 1] - '0') + 1 + '0');
                }

            }

            if (flag == 0)
            {
                //cout << str << endl;
                return -1;
            }


        }
    }
}


string generate_first_key(string enc_msg)
{
    string str = "1";
    int tmp = enc_msg.length() - 1;
    for (int i = 0; i < tmp; i++)
    {
        str += "0";
    }
    return str;
}


int main()
{
    string message = "aaaapookaaaaa";
    string key = "11222";
    string encrypted_text = encryption(message, key);
    string clue = "pook";
    string str = generate_first_key(encrypted_text);
    string str1 = "100";
    while (str1.length() != str.length())
    {
        int tmp = foo(str1, encrypted_text, clue);
        if (tmp == -1)
        {
            //str1[0] = 1;
            str1 += "0";
            continue;
        }
        else
        {
            return 0;
        }
    }
}