class Node
{
	public:
		int data;
		Node* next;
                
		//Constructor that to built new node wiht given data
	        Node(int value);
};

class List
{
	public:
		Node* m_first;
		Node* m_last;
		int m_size;
                
		//Constructor
                List();

		//Function that return size
		int get_size();

		//Function that to check if list is empty
		bool is_empty();
                
		//Function that add new node given data to the end of the list
		void push_back(int data);

		//Function that tom print data in each node of the lsit
		void print();
                
                //Indexing operator	
		int& operator[](int index);
                
		//Remove last element in list
		void pop_back();
                
		//Function that add value appropriate of index list
		void insert(int index,int value);
                
	        //Function that remove value in list	
		void remove_value(int value);
                
		//Function that remove index in list
		void remove_index(int index);

		//Copy constructor
                List(const List& other);

		//Destructor
		~List();
};
