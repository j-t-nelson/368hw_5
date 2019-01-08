/* ******************************************************
 * Name: Jasper Nelson
 * Wisc ID: 9073545106
 * OS: MAC
 * IDE (or text editor): Eclipse
 * Compiler: Eclipse
 * How long did the assignment take you to complete in minutes: 300
 * What other resources did you consult (copy and paste links below):
 * cplusplus.com
 * stackoverflow.com
*/ //******************************************************

#ifndef ITEM_H_
#define ITEM_H_

using namespace std;

class ITEM {
public:
	string name;
	int quantity;

	//item constructor that returns an item object with name "" and quantity 0
	ITEM() : name(""), quantity(0){}

	//item destructor
	virtual ~ITEM() {}

	//item constructor that allows you to specify name
	ITEM(string name) : name(name), quantity(0) {}

	//interface for each Processs_Purchase function
	virtual bool Process_Purchase(istream &cin, ostream &cout) = 0;

	//interface for each Get_Cost function
	virtual int Get_Cost() const = 0;

	//overrides the '<' operator to allow for comparison
	bool operator<(const ITEM& rhs) {
		return this->name < rhs.name;
	}

	//interface for the print functioin for each item type
	virtual void Print(ostream &out=cout) const = 0;
};


ostream & operator<<(ostream &out, const ITEM &rhs) {
	rhs.Print(out);
	return out;
}
bool compare_pointers_to_items(ITEM *lhs, ITEM *rhs) {
	return *lhs < *rhs;
}


class BALLS : public ITEM
{
public:

	/*
	 * purpose: allows the user to select the quantity and size of the ball they want to buy
	 * input: the current cin and cout to write to and from
	 * output: true if the operation works, else false
	 */
	bool Process_Purchase(istream &cin, ostream &cout)
	{
		cout << endl;
		cout << "Cannon Balls come in three sizes:" << endl;
		cout << "  1) Small     6 pieces of eight per Cannon Ball" << endl;
		cout << "  2) Medium   15 pieces of eight per Cannon Ball" << endl;
		cout << "  3) Large    52 pieces of eight per Cannon Ball" << endl;
		cout << "What size would you like? ";
		cin >> size;
		if(size < 1 || size > 3) return false;

		cout << "How many would you like? ";
		cin >> quantity;

		if (quantity > 0) cout << "Happy hunting!" << endl;
		else return false;
		//essage();
		return true;
	}
	/*
	 * purpose: constructs a ball object with size 0
	 * input: n/a
	 * returns: a ball object
	 *
	 */
	BALLS()
	{
		size = 0;
		name = "Cannon Ball";


	}
	/*
	 * deconstructs the ball object
	 */
	~BALLS(){}

	/*
	 * prints out the quantity and type of cannon ball purchased
	 * inputs: current cout
	 * outputs:n/a
	 */
	void Print(ostream &out=cout) const
	{
		if(size == 1)
		{
			out << quantity << " Small " << name;
			if(quantity != 1) out << "s";
		}
		if (size == 2)
		{
			out << quantity << " Medium " << name;
			if(quantity != 1) out << "s";
		}
		if (size == 3)
		{
			out << quantity << " Large " << name;
			if(quantity != 1) out << "s";
		}
	}
	/*
	 * purpose: returns the total cost of the purchase
	 * input:n/a
	 * returns: integer value of the cost of the entire purchase
	 */
	int Get_Cost() const
	{
		if (size == 1) return quantity * 6;
		if (size == 2) return quantity * 15;
		if (size == 3) return quantity * 52;

		return -1;
	}


private:
	int size;

};

class RUM : public ITEM
{
public:
	/*
	 * purpose: allows the user to select the quantity and type of rum they want to buy
	 * input: the current cin and cout to write to and from
	 * output: true if the operation works, else false
	 */
	bool Process_Purchase(istream &cin, ostream &cout)
	{
		cout << endl;
		cout << "We have three different qualities of Rum in stock:" << endl;
		cout << "  1) Swill     1 pieces of eight per barrel" << endl;
		cout << "  2) Grog      5 pieces of eight per barrel" << endl;
		cout << "  3) Fine Rum 19 pieces of eight per barrel" << endl;
		cout << "What kind would you like? ";
		cin >> quality;
		if (quality < 1 || quality > 3) return false;

		if(quality == 1) cout << "Gotta keep the crew happy!"<< endl;
		if(quality == 2) cout << "The officers will love it!"<< endl;
		if(quality == 3) cout << "Nothing but the best for the captain!" << endl;

		cout << "How many barrels would you like? ";
		cin >> quantity;

		if (quantity < 1) return false;
		return true;
	}
	/*
	 * purpose: constructs a rum object with a quality type of 0
	 * input: n/a
	 * returns: a rum object
	 */
	RUM()
	{
		name = "Rum";
		quality = 0;

	}
	//rum object destructor
	~RUM(){}

	/*
	 * prints out the quantity and type of rum purchased
	 * inputs: current cout
	 * outputs:n/a
	 */
	void Print(ostream &out=cout) const
	{
		if(quality == 1)
		{
			if(quantity == 1) out << quantity <<" Barrel of Swill";
			else out << quantity << " Barrels of Swill";
		}
		if (quality == 2)
		{
			if(quantity == 1) out << quantity <<" Barrel of Grog";
			else out << quantity << " Barrels of Grog";
		}
		if (quality == 3)
		{
			if(quantity == 1) out << quantity <<" Barrel of Fine Rum";
			else out << quantity << " Barrels of Fine Rum";
		}
	}

	/*
	 * purpose: returns the total cost of the purchase
	 * input:n/a
	 * returns: integer value of the cost of the entire purchase
	 */
	int Get_Cost() const
	{
		if (quality == 1) return quantity;
		if (quality == 2) return quantity * 5;
		if (quality == 3) return quantity * 19;

		return -1;
	}


private:
	int quality;
};


class LIMES : public ITEM
{
public:
	/*
	 * purpose: allows the user to select the quantity of limes they want to buy
	 * input: the current cin and cout to write to and from
	 * output: true if the operation works, false else
	 */
	bool Process_Purchase(istream &cin, ostream &cout)
	{
		cout << endl;
		cout << "Limes arrr delicious. They're on sale for 7 pieces of eight per dozen." << endl;
		cout << "How many dozen would you like? ";
		cin >> quantity;

		if (quantity < 1) return false;

		return true;
	}
	/*
	 * purpose: constructor for the limes class
	 * input:n/a
	 * returns: a lime object that cost 7
	 */
	LIMES()
	{
		name = "Limes";
		cost = 7;


	}
	//lime object destructor
	~LIMES(){};

	/*
	 * purpose: returns the total cost of the purchase
	 * input:n/a
	 * returns: integer value of the cost of the entire purchase
	 */
	int Get_Cost() const
	{
		return quantity * 7;
	}

	/*
	 * prints out the quantity and type of cannon ball purchased
	 * inputs: current cout
	 * outputs:n/a
	 */
	void Print(ostream &out=cout)const
	{
		out << quantity * 12 << " Limes";
	}


private:
	int cost;

};
class APPAREL : public ITEM
{
public:
	/*
	 * purpose: allows the user to select the type of apparel they want to buy
	 * input: the current cin and cout to write to and from
	 * output: true if the operation works, false else
	 */
	bool Process_Purchase(istream &cin, ostream &cout)
	{
		cout << endl;
		cout << "That looks like a rough injury."  << endl;
		cout << "  1) Eyepatch  4 pieces of eight" << endl;
		cout << "  2) Pegleg   13 pieces of eight" << endl;
		cout << "  3) Hook     43 pieces of eight" << endl;
		cout << "You're going to need a ... ";
		cin >> type;
		if(type < 1 || type > 3) return false;


		return true;
	}

	/*
	 * purpose: creates an apparel object
	 * input:n/a
	 * returns: an apparel object
	 */
	APPAREL()
	{
		quantity = 1;
		name = "Apparel";
		type = 0;


	}
	//apparel object destructor
	~APPAREL(){};

	/*
	 * purpose: returns the total cost of the purchase
	 * input:n/a
	 * returns: integer value of the cost of the entire purchase
	 */
	int Get_Cost() const
	{
		if (type == 1) return 4;
		if (type == 2) return 13;
		if (type == 3) return 43;

		else return 0;
	}

	/*
	 * prints out the quantity and type of cannon ball purchased
	 * inputs: current cout
	 * outputs:n/a
	 */
	void Print(ostream &out=cout) const
	{
		if(type == 1) out << "1 Eyepatch";
		if(type == 2) out << "1 Pegleg";
		if(type == 3) out << "1 Hook";
	}
private:
	int type;

};
#endif
