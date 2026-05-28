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

        
    }
};