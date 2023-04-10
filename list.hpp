class Node
{
	public:
		int m_data;
		Node* m_next;
                
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
};
