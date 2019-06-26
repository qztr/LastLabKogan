#include <map>
#include <string>
#include <iostream>
using namespace std;

int main()
{

    std::multimap<string, string>::iterator it;
    std::multimap<int, string>::iterator its;

    multimap<string, string> m_i;
    multimap<int, string> m_d;

    int x = -1;
    int y = -1;
    string key_init;
    string data_init;
    int date_init;
    //cout << "Choose action: \n";
    //cout << "1)Map with key second name of author\n2)Map with key Book creatrion year \n";
    //while (x != 0)
    //{
        //cin >> x;
        //if (x == 1)
        //{
            while (y != 0)
            {
                cout << "\n1)Add to map\n2)Del book\n3)Print map sorted by Author`s name \n4)Print map sorted by year when book was writen\n"
                     << endl;
                cin >> y;
                if (y == 1)
                {
                    cout << "enter initials of author to insert\n";
                    cin >> key_init;
                    cout << "enter year when book was writen to insert\n";
                    cin >> date_init;
					cout << "enter information about book: name, count of books\n";
                    cin >> data_init;
					m_d.insert(pair<int, string>(date_init, data_init));
                    m_i.insert(pair<string, string>(key_init, data_init));

                }
                if (y == 2)
                {
                    cout << "enter authors name of book to delete from map\n " << endl;
                    cin >> key_init;
                    m_i.erase(key_init);
                    cout << "enter release date  of book to delete from map\n " << endl;
                    cin >> date_init;
                    m_d.erase(date_init);
                }
                if (y == 3)
                {
                    for (it = m_i.begin(); it != m_i.end(); ++it)
                        std::cout << (*it).first << " => " << (*it).second;
					cout << endl;
					for (its = m_d.begin(); its != m_d.end(); ++its)
                        std::cout <<", "<< (*its).first << '\n';
					cout << endl;
                }
				if (y == 4)
                {
                    for (its = m_d.begin(); its != m_d.end(); ++its)
                        std::cout << (*its).first << " => " << (*its).second;
					cout << endl;
					for (it = m_i.begin(); it != m_i.end(); ++it)
                        std::cout <<", "<< (*it).first << '\n';
					cout << endl;
                }
                if (y == 0)
                {
                    return 0;
                }
                key_init = "";
                data_init = "";
            };
      //  }
        /*if (x == 2)
        {
            while (y != 0)
            {
                cout << "1)Add to map\n2)Del by Data\n3)Print map\n"
                     << endl;
                cin >> y;
                if (y == 1)
                {
                    cout << "enter year when the book was realeased to insert\n";
                    cin >> date_init;
                    cout << "enter information about book: initials of the author,release date, count of books\n";
                    cin >> data_init;
                    m_d.insert(pair<int, string>(date_init, data_init));
                }
                if (y == 2)
                {
                    cout << "enter year of book created to delete from map\n " << endl;
                    cin >> date_init;
                    m_d.erase(date_init);
                }
                if (y == 3)
                {
                    for (its = m_d.begin(); its != m_d.end(); ++its)
                        std::cout << (*its).first << " => " << (*its).second << '\n';
                }
                if (y == 0)
                {
                    return 0;
                }
                key_init = "";
                data_init = "";
            };
        }
        if (x == 0)
        {
            return 0;
        }*/
    //};
}
