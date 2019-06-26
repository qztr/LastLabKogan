#include <iostream>
using namespace std;

template <typename T>
class list
{
private:
    class node //Класс node содержит данные списка
    {
        friend class list<T>;

    private:
        node *next; //Указатель на следующий элемент в списке
        T val;      //Данные списка

        node() : next(NULL) {}
        ~node() {}
    };

    node *head; //Указатель на начало списка
    int count;  //Количество элементов в списке
public:
    list() : head(NULL), count(0) {}
    ~list()
    {
        clear(); //Функция освобождает память, используемую для хранения списка
    }
    int getCount() const //Возвращает количество элементов в списке
    {
        return count;
    }

    int add(T data) //Добавление элемента в конец списка. Возвращает количество элементов в списке
    {
        node *to_add = new node;
        to_add->next = NULL;
        to_add->val = data;
        if (head == NULL) //Если в списке нет элементов
            head = to_add;
        else
        {
            node *current;
            for (current = head; current->next != 0; current = current->next)
                ;
            current->next = to_add;
        }
        count++;
        return count;
    }

    int del(int x) //Удаление элемента из списка. Возвращает количество элементов в списке.
    {              //Возвращает -1, если произошла ошибка
        if (x > count)
            return -1;
        node *to_del = head;
        if (x == 1) //Если нужно удалить первый элемент
        {
            head = head->next;
            delete to_del;
        }
        else
        {
            node *current = head;
            for (int i = 1; i < x - 1; i++)
                current = current->next;
            to_del = current->next;
            current->next = current->next->next;
            delete to_del;
        }
        count--;
        return count;
    }

    void clear() //Очистка списка
    {
        node *current = head;
        node *to_del = head;
        while (to_del != NULL)
        {
            current = current->next;
            delete to_del;
            to_del = current;
        }
        head = NULL;
        count = 0;
    }

    T getData(int x) const //Возвращает данные из списка.
    {
        node *current;
        for (current = head; x > 1; x--)
            current = current->next;
        return current->val;
    }
};

int main()
{
	int ind=0;
	int num=-1; int d=0; double d1=0; float d2=0;
	list<int> my_list;
	list<double> my_list2;
	list<float> my_list3;
	while (num != 0){
		cout << "Pick some: "<< endl;
		cout <<"1)add element to list INT\n2)add element to list DOUBLE\n3)add element to list FLOAT\n";
		cout <<"4)Print list INT\n5)Print list DOUBLE\n6)Print list FLOAT"<<endl;
		cout <<"7)Del element of list INT\n8)Del element of list DOUBLE\n9)Del element of list FLOAT\n10)clear all lists"<<endl;
		cin >> num;
		if (num == 1){
			cout << "Enter data to insert:\n"<< endl;
	        cin >> d;
	        my_list.add(d);
		}

		if (num == 2){
			cout << "Enter data to insert:\n"<< endl;
	        cin >> d1;
	        my_list2.add(d1);
		}

		if (num == 3){
			cout << "Enter data to insert:\n"<< endl;
	        cin >> d2;
	        my_list3.add(d2);
		}

		if (num == 4){
			cout << endl;
            for (int i = 1; i <= my_list.getCount(); i++)
            cout << my_list.getData(i) << " ";
            cout << endl;
		}

		if (num == 5){
			cout << endl;
            for (int i = 1; i <= my_list2.getCount(); i++)
            cout << my_list2.getData(i) << " ";
            cout << endl;
		}
		if (num == 6){
		    cout << endl;
            for (int i = 1; i <= my_list3.getCount(); i++)
            cout << my_list3.getData(i) << " ";
			cout << endl;
		}
		if (num == 7){
			cout << "insert index of element to del: "<<endl;
			cin >> ind;
			my_list.del(ind);
			cout << endl;
		
		}
		if (num == 8){
			cout << "insert index of element to del: "<<endl;
			cin >> ind;
			my_list.del(ind);
			cout << endl;
		}
		if (num == 9){
			cout << "insert index of element to del: "<<endl;
			cin >> ind;
			my_list.del(ind);
			cout << endl;
		}
		if (num == 10){
			cout << "all cleared"<<endl;
			my_list3.clear();
            my_list2.clear();
            my_list.clear();
		}
		cout << endl;
		cout << endl;
	}




    //Пример использования списка с типом int
    //list<int> my_list;

    //for (int i = 0; i < 5; i++)
    //    my_list.add(i);

    //cout << my_list.getCount() << endl;
    //for (int i = 1; i <= my_list.getCount(); i++)
    //    cout << my_list.getData(i) << " ";
    //cout << endl;

//	int d=0;
	//list<int> ilist;
	//cout << "Enter data to insert:\n"<< endl;
	//cin >> d;
	//ilist.add(d);



	//ilist.del(0);

    //ilist.del(1);

 //  ilist.del(2);


	//for (int i = 1; i <= ilist.getCount(); i++)
 //       cout << ilist.getData(i) << " ";
 //   cout << endl;




    ////Пример использования списка с типом double
    //list<double> my_list2;
    //double kd = 0.001;
    //for (int i = 0; i < 5; i++)
    //{
    //    kd = i + 0.11;
    //    my_list2.add(kd);
    //};

    //cout << my_list2.getCount() << endl;
    //for (int i = 1; i <= my_list2.getCount(); i++)
    //    cout << my_list2.getData(i) << " ";
    //cout << endl;

    ////Пример использования списка с типом float
    //list<float> my_list3;
    //float kf = 0.0012;
    //for (int i = 0; i < 5; i++)
    //{
    //    kf = i + 0.11;
    //    my_list3.add(kf);
    //};

    //cout << my_list3.getCount() << endl;
    //for (int i = 1; i <= my_list3.getCount(); i++)
    //    cout << my_list3.getData(i) << " ";
    //cout << endl;


    

	system("pause");
    return 0;
}
