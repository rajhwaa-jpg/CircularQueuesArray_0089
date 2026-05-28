#include <iostream>
using namespace std;

class Queues
{
private:
    static const int max = 3;
    int FRONT, REAR;
    int queue_array[max];
   
public:
    Queues()
    {
        FRONT = -1;
        REAR = -1;
    }

    void insert()
    {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        //cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR +1))
        {
            cout << "\nQueue overflow\n";
            return;
        }

        //cek apakahh antrian kosong
        if (FRONT == -1)
        {
            FRONT = 0;
            REAR = 0;    
        }
        else
        {
            //jika rear berada di posisi terakhir array, kembali ke awal array
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;
    }

    void remove()
    {
        //cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "queue underflow\n";
            return;
        }
        cout << "\nthe element delete from the queue is: " << queue_array[FRONT] << "\n";

        //cek jika antrian hanya memiliki 1 elemen
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else{
            //jika elemen yang di hapus  berada di posisi terakhir array, kembali k awal array
            if (FRONT == max - 1)
            FRONT = 0;
            else
            FRONT = FRONT + 1;
        }
    }

    void display()
    {
        int FRONT_position = FRONT;
        int REAR_position = REAR;

        //cek apakah antrian kosong
        if (FRONT_position == -1)
        {
            cout << "queue is empty\n";
            return;
        }
        cout << "\nelements in te queue are....\n";

        //jika FRONT <= REAR, iterasi dri FRONT hingga REAR
        if (FRONT_position <= REAR_position)
        {
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
        }
        else
        {
            //jika FRONT > REAR, iterasi dari FRONT hingga akhir array
            while (FRONT_position <= max - 1)
            {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            //iterasi dari awal array hingga REAR
            FRONT_position = 0;
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
        }
    }
};

int main()
{
    Queues q;
    char ch;

    while (true)
    {
        try
        {
            cout << "menu" << endl;
            cout << "1. implement insert operation" << endl;
            cout << "2. implement delete operation" << endl;
            cout << "3. display values" << endl;
            cout << "4. exit" << endl;
            cout << "enter your choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch)
            {
            case '1':
            {
                q.insert();
                break;
            }
            case '2':
            {
                q.remove();
                break;
            }
            case '3':
            {
                q.display();
                break;
            }
            case '4':
            {
                exit(0);
            }
            default:
            {
                cout << "Invalid option" << endl;
                break;
            }
            }
        }
        catch (exception &e)
        {
            cout << "check for the values entered." << endl;
        }
    }
    return 0;
}