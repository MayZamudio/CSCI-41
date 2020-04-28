#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

template<class T>
class LL { //A single node in a linked list
	T data = {}; //There is a class invariant stating cost can never be negative. Enforce this rule below.
	LL *prev = nullptr;
	LL *next = nullptr;
	public:
	//This is a default constructor, 1 parameter constructor, 2 param, 3 param, and 4 param in one!
	LL(T new_data, LL *new_prev = nullptr, LL *new_next = nullptr) {
		set_data(new_data);
		set_next(new_next);
		set_prev(new_prev);
		//YOU
	}
	T get_data() {
		return data;//YOU
	}
	void set_data(int new_data) {
		data = new_data;
	}
	LL *get_next() { 
		return next;//YOU
	}//if it's a void, your setting something
	void set_next(LL *new_next) { 
		next = new_next;//YOU
	}//if it's a pointer, you're returning
	LL *get_prev() { 
		return prev;//YOU
	}
	void set_prev(LL *new_prev) { 
		prev = new_prev;//YOU
	}
};

template <class T>
class List {
	LL<T> *head = nullptr;
	LL<T> *tail = nullptr;
	size_t size = 0;
	public:
	List() {} //Set above
	~List() { //This should free all memory allocated in this list
		while (head) {
			LL<T> *temp = head->get_next();
			delete head;
			head = temp;
		}
		//YOU: one delete for every new
	}
	size_t get_size() const { 
		return size;//YOU
	} 

	std::string print_list() const {
		LL<T> *temp = head;
		std::ostringstream ss; //This lets us write to a string like we do to cout
		if (!temp) {
			ss << "Empty List\n";
			return ss.str(); //Converts the stringstream to a string so we can return it
		}
		int counter = 0;
		while (temp) {
			ss << "Node " << to_string(counter) << ": " << temp->get_data() << endl;
			temp = temp->get_next();
			counter++;
		}
		return ss.str();
	}
	bool search ( const T  old_data) {
		LL<T>* temp = head;
		while (temp) {
			if (temp->get_data() == old_data) {
			 return true;
			}
			temp = temp->get_next();
		}
		return false;
	}
	void insert_at_beginning(T new_data) {
		//YOU: Write code to make a new node and insert at the head
		if (size == 0) head = tail = new LL<T>(new_data);
		else{									  //Prev   Next
			head->set_prev(new LL<T>(new_data, NULL, head));
			head = head->get_prev();
		}
		size++;
		//Make sure size gets updated when you add to the list
	}
	void push_back(T new_data) {
		if (size == 0) head = tail = new LL<T>(new_data);
		else {
			LL<T> *temp = new LL<T>(new_data, tail);
										 //Prev  Next
			tail->set_next(temp);
			temp->set_prev(tail);
			tail = temp;
		}
		size++;
	}
	T pop(){
		LL<T> *temp = head;
		T x = temp->get_data();
		head = head->get_next();
		delete temp;
		size--;
		return x;
	}

	//This function will delete a single node from the LL with a cost <= amount
	//amount_out will hold how much change was left over after the delete was done
	//It will return sentence containing "X deleted\n" (if node X was deleted) or "Nothing deleted"
	
	bool remove(T old_data) {
		if (size == 0)
			return false;
		LL<T> *temp = head;
		//YOU: Second, handle there being one element in the list
		if (size == 1){
			if (temp->get_data() == old_data) {
				delete temp;
				head = tail = nullptr;
				size--;
				return true;
			}
		}
		//YOU: Third, handle deleting from the head or tail 
		while (temp) {
			if (temp->get_data() == old_data) {
				if (temp == head){
					head = head->get_next();
					head->set_prev(nullptr);
					delete temp;
					size--;
					return true;
				} else if (temp == tail) {
					tail = tail->get_prev();
					tail->set_next(NULL);
					delete temp;
					size--;
					return true;
				} else {
                    temp->get_prev()->set_next(temp->get_next());
					temp->get_next()->set_prev(temp->get_prev());	
					delete temp;
					size--;
					return true;
				}
			} 
			temp = temp->get_next();
		}
		return true;
	}
};

