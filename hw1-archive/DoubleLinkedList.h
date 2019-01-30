// DoubleLinkedList.h
struct Node {
	long long num;
	Node* prev;
	Node* next;
};

class DoubleLinkedList {
public:
	
	int getNOD()
	{

		return nod;
	}
	int getNextData()
	{
		if (c == head)
		{
			return 0;
		}


		return c->num;


	}
	void Insert(int num)
	{
		Node * nd = new Node();
		nd->num = num;
		nd->next = head->next;
		nd->prev = head;

		head->next->prev = nd;
		head->next = nd;
		nod++;
	}

	int getDPN()
	{
		return m_digitsPerNode;
	}
	int getFirstData()
	{
		c = tail->prev;
		return c->num;
	}
	bool moveNext()
	{
		if (c == head)
		{
			return false;
		}

		c = c->prev;
		return true;
	}
	void Print()
	{
		Node * c = head->next;
		string line = to_string(c->num);

		while (c != tail)
		{

			cout << c->num;
			c = c->next;
		}
	}

	DoubleLinkedList() {		
		head = new Node();
		tail = new Node();

		head->next = tail;
		head->prev = NULL;
		tail->prev = head;
		tail->next = NULL;

		m_digitsPerNode = 0;

	};
	DoubleLinkedList(int n) {		
		head = new Node();
		tail = new Node();

		head->next = tail;
		head->prev = NULL;
		tail->prev = head;
		tail->next = NULL;
		nod = 0;
		m_digitsPerNode = n;
	};   // default construct

	~DoubleLinkedList() {};  // deconstruct
	DoubleLinkedList(const std::string& num, int digitsPerNode) {
		head = new Node();
		tail = new Node();
		nod = 0;
		head->next = tail;
		head->prev = NULL;
		tail->prev = head;
		tail->next = NULL;
		m_digitsPerNode = digitsPerNode;
		int numberNode = 0;
		int remainNum = 0;
		int tnum = 0;
		numberNode = num.length() / digitsPerNode;
		remainNum = num.length() % digitsPerNode;


		if (remainNum != 0)							//add another node if theres a remainder
		{
			numberNode++;
		}

		int i = num.length() - 1;

		int count = num.length() - 1;

		int checkNum = 0;

		if (remainNum == 0) {

			for (int i = 0; i < numberNode; i++)
			{
				for (int j = 0; j < digitsPerNode; j++)
				{
					tnum = tnum + (num[count--] - 48) * pow(10, checkNum++);

				}

				this->Insert(tnum);
				checkNum = 0;
				tnum = 0;
			}

		}
		else
		{
			for (int i = 0; i < numberNode - 1; i++)
			{
				for (int j = 0; j < digitsPerNode; j++)
				{
					tnum = tnum + (num[count--] - 48) * pow(10, checkNum++);
				}
				this->Insert(tnum);
				checkNum = 0;
				tnum = 0;
			}
		}

		if (remainNum != 0)
		{
			for (int i = 0; i < remainNum; i++)
			{
				tnum = tnum + (num[count--] - 48) * pow(10, checkNum++);
			}
			this->Insert(tnum);
		}
	}; // user defined construct
	
	DoubleLinkedList(const DoubleLinkedList& list) {};  // copy construct
	DoubleLinkedList& operator = (const DoubleLinkedList& list) {};  // assignment consturct
public:

	//mandatory
	DoubleLinkedList operator + (const DoubleLinkedList& list) const {};
	DoubleLinkedList operator * (const DoubleLinkedList& list) const {};

	// optional
	DoubleLinkedList operator - (const DoubleLinkedList& list) const {};
	// 10% extra 
	DoubleLinkedList operator / (const DoubleLinkedList& list) const {};
	// 20% extra
	DoubleLinkedList Sqrt(const DoubleLinkedList& list) const {};

private:
	Node* head;
	Node* tail;
	Node* n;
	Node* list1;
	Node* list2;
	Node* c;
	int m_digitsPerNode;
	int nod;
	long long remainder; // for / operator
	float decimal;  // for sqrt()  7 valid digits.
};

void add(DoubleLinkedList& l1, DoubleLinkedList& l2)
{
	DoubleLinkedList l3(l1.getDPN());

	int carry = 0;
	int power = pow(10, l1.getDPN());
	int resultNum = 0;

	resultNum = l1.getFirstData() + l2.getFirstData();
	if (resultNum >= power)
	{
		carry = 1;
		resultNum = resultNum % power;
	}

	l3.Insert(resultNum);
	int num1 = 0;
	int num2 = 0;

	for (int i = 0; i < l1.getNOD() - 1; i++) {

		if (l1.moveNext() == true) {
			num1 = l1.getNextData();
		}

		if (l2.moveNext() == true)
		{
			num2 = l2.getNextData();
		}

		resultNum = num1 + num2 + carry;

		if (resultNum >= power)
		{
			carry = 1;
			resultNum = resultNum % power;
		}
		else
		{
			carry = 0;
		}
		l3.Insert(resultNum);
		num1 = 0;
		num2 = 0;
	}
	if (carry != 0)
	{
		l3.Insert(carry);
	}
	l3.Print();
}

// Node* temp = head;
//while(temp != NULL) {
//		cout<<temp->num;
//		temp = temp->next;


// gethead func = return address of head of a list
// gettail func = return address of tail of a list
// print func = 1. access to head and then move to tail to print out each data
// append func = to save data into result node
// check func = zero data in a node is whether is only 0 or multiple 0
////////////above addition part
// remove leading zero func = if a data save in a list like 0001 then you should remove 000< to get just 1
// removeall func if you want to use a list again then you need to reset the list