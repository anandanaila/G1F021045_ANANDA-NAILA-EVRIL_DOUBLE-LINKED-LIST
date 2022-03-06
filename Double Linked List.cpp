#include<iostream>
using namespace std;


struct Tanggal_Lahir{
	string Bulan;
	int Tahun,Tanggal;
	
	Tanggal_Lahir *prev;
	Tanggal_Lahir *next;
};

Tanggal_Lahir *head, *tail, *cur, *newNode, *del, *afterNode ;


void createDoubleLinkedList(int Tanggal, string Bulan, int Tahun){
	head = new Tanggal_Lahir();
	head->Tanggal = Tanggal;
	head-> Bulan = Bulan;
	head->Tahun = Tahun;
	head->prev = NULL;
	head->next = NULL;
	tail = head;
}


int countDoubleLinkedList()
{
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!";
  }else{
    cur = head;
    int jumlah = 0;
    while( cur != NULL ){
      jumlah++;      
      
      cur = cur->next;
    }
    return jumlah;
  }
}


void insertFirst(int Tanggal, string Bulan, int Tahun){
	if( head == NULL ){
    cout << "Double Linked List belum dibuat!";
  	}else{
	newNode = new Tanggal_Lahir ();
	newNode->Tanggal = Tanggal;
	newNode->Bulan  = Bulan;
	newNode->Tahun = Tahun;
	newNode->prev = NULL;
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
	}
}

void insertLast(int Tanggal, string Bulan, int Tahun){
	if( head == NULL ){
    cout << "Double Linked List belum dibuat!";
  	}else{
	newNode = new Tanggal_Lahir();
	newNode->Tanggal = Tanggal;
	newNode->Bulan = Bulan;
	newNode->Tahun = Tahun;
	newNode->prev = tail;
	newNode->next = NULL;
	tail->next = newNode;
	tail = newNode;
	}
}


void insertAfter(int Tanggal, string Bulan, int Tahun, int posisi){
	if( head == NULL ){
    cout << "Double Linked List belum dibuat!";
 	 }else{
	newNode = new Tanggal_Lahir();
	newNode->Tanggal = Tanggal;
	newNode->Bulan = Bulan;
	newNode->Tahun = Tahun;

	cur = head;
	int nomor = 1;
	while(nomor < posisi -1){
		cur =  cur->next;
		nomor++;
	}
	
	afterNode = cur->next;
	newNode->prev = cur;
	newNode->next = afterNode;
	cur->next =newNode;
	afterNode->prev = newNode;
	}
}


void deleteFirst(){
	if( head == NULL ){
    cout << "Double Linked List belum dibuat!";
	  }else{
	del = head;
	head = head->next;
	head->prev = NULL;
	delete del;
	}
}


void deleteLast(){
	if( head == NULL ){
    cout << "Double Linked List belum dibuat!";
  	}else{
	del = tail;
	tail = tail->prev;
	tail->next =NULL;
	delete del;
	}
}


void deleteAfter(int posisi){
	if( head == NULL ){
    cout << "Double Linked List belum dibuat!";
 	 }else{
 	 	if( posisi == 1 || posisi == countDoubleLinkedList() ){
      		cout << "Posisi bukan posisi tengah!" << endl;
   		}else if( posisi < 1 || posisi > countDoubleLinkedList() ){
      		cout << "Posisi diluar jangkauan!" << endl;
   		}else{
			int nomor = 1;
			cur = head;
			while(nomor <= posisi -1){
				cur = cur->next;
				nomor++;
				}
			del = cur->next;
			afterNode = del->next;
			cur->next =afterNode;
			afterNode->prev = cur;
			delete del;
		}
	}
}


void printDoubleLinkedList(){
	if( head == NULL ){
    cout << "Double Linked List belum dibuat!";
  	}else{
    cout << "\nJumlah Data : " << countDoubleLinkedList() << endl;
    cout << "INFO DATA" << endl;
    cur = head;
    while( cur != NULL ){
     
      cout << "Data : " << cur->Tahun << endl;
      
      cur = cur->next;
    }
  }
}

void searchNode(Tanggal_Lahir **head, int Tahun ){
    int currentTT = 2021;
    Tanggal_Lahir*cur = *head;
    while (cur->next != 0 && currentTT != Tahun)
    {
        cur = cur->next;
        currentTT++;
    }
    cout << cur->Tanggal << " Lahir Pada Tahun Ke " << currentTT;
}

int main(){
	
	createDoubleLinkedList(11,"Januari",1974);
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	insertFirst(20, "Januari", 2014);
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	insertLast(13, "Maret", 2006);
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	insertAfter(17, "Juni", 2004, 3);
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	insertAfter(16, "Juli", 2016, 4);
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	deleteFirst();
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	deleteLast();
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	deleteAfter(3);
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	printDoubleLinkedList();
  	searchNode(&head, 3);
	return 0;
}
