#include <iostream>
using namespace std;

class queues {
	int FRONT, REAR, max = 5;   
	int queve_array[5];          

public:
	queues() {
		FRONT = -1;
		REAR = -1;
	}

	void insert() {
		int num;
		cout << "Enter a number: ";
		cin >> num;
		cout << endl;

		//Cek apakah antrian penuh
		if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
			cout << "\nQueve overflow\n";
			return;
		}

		//Cek apakah antrian kosong
		if (FRONT == -1) {
			FRONT = 0;
			REAR = 0;
		}
		else {
			//Jika REAR berada di posisi terakhir array, kembali ke awal array
			if (REAR == max - 1)
				REAR = 0;
			else
				REAR = REAR + 1;
		}
		queve_array[REAR] = num;
	}

	void remove() {
		//Cek apakah antrian kosong
		if (FRONT == -1) {
			cout << " Queve Underflow\n";
			return;
		}
		cout << "\nThe element deleted from the queve is: " << queve_array[FRONT] << "\M";

		//Cek jika antrian hanya memiliki satu elemen
		if (FRONT == REAR) {
			FRONT = -1;
			REAR = -1;
		}
		else {
			// jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
			if (FRONT == max - 1)
				FRONT = 0;
			else
				FRONT = FRONT + 1;
		}
	}

	void display() {
		int FRONT_position = FRONT;
		int REAR_position = REAR;

		//cek apakah antran kosong
		if (FRONT == -1) {
			cout << "Queve is empty\n";
			return;
		}

		cout << "\nElements in the queve are..\n";

		// Jika FRONT_posisition <= REAR_posisition, literasi dari Front hingga REAR
		if (FRONT_position <= REAR_position) {
			while (FRONT_position <= REAR_position) {
				cout << queve_array[FRONT_position] << "  ";
				FRONT_position++;
			}
			cout << endl;
		}
		else {
			//Jika FRONT_position > RAER_position, literasi dari FRONT hingga akhir array
			while (FRONT_position <= max - 1) {
				cout << queve_array[FRONT_position] << "  ";
				FRONT_position++;
			}

			FRONT_position = 0;

			// literasi dari awal array hingga REAR
			while (FRONT_position <= REAR_position) {
				cout << queve_array[FRONT_position] << "   ";
				FRONT_position++;
			}
			cout << endl;
		}
	}
};

int main() {
	queues q;
	char ch;

	while (true) {
		try {
			cout << "Menu" << endl;
			cout << "1. Implement insert operation" << endl;
			cout << "2. Implement delete operation" << endl;
			cout << "3. Display values" << endl;
			cout << "4. Exit" << endl;
			cout << "Enter your choice (1-4): ";
			cin >> ch;
			cout << endl;

			switch (ch) {
			case '1': {

				q.insert();
				break;
			}
			case '2': {
				q.remove();
				break;

			}
			case'3': {
				q.display();
				break;
			}
			case'4': {
				return 0;

			}
			default: {
				cout << "invalid option!!" << endl;
				break;

			}
			}

		}
		catch (exception& e) {
			cout << "Check for the values entered." << endl;
		}
	}

	return 0;
}
