/*
 * waterjug.cpp
 *
 *  Created on: Oct 14, 2016
 *      Author: Zach Saegesser
 *      I pledge my honor that I have abided by the STevens honor System
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;


class State {
public:
	//constructor-initialization
	State(int a, int b, int c, string path, int A, int B, int C) : a_(a), b_(b), c_(c), path_(path), capA_(A), capB_(B), capC_(C) { }
	/**
	* A State object (jug state) has 7 elements
	* a->the current amount of water in the first jug
	* b->the current amount of water in the second jug
	* c->the current amount of water in the third jug
	* path->the string representation of what pouring actions were done to reach that jug state
	* A->the max amount of water the first jug can hold
	* B->the max amount of water the second jug can hold
	* C->the max amount of water the third jug can hold
	*
	*/

	//getters and setters for the individual jugs
	int getA(){
		return a_;
	}
	int getB(){
		return b_;
	}
	int getC(){
		return c_;
	}
	int getCapA(){
		return capA_;
	}
	int getCapB(){
		return capB_;
	}
	int getCapC(){
		return capC_;
	}
	void setA(int newA){
		a_ = newA;
	}
	void setB(int newB){
		b_ = newB;
	}
	void setc(int newC){
		c_ = newC;
	}

	//the path is a string that is extended in each 'pour' to represent what actions were taken to reach that set of jug states
	void setPath(string newpath){
		path_ = newpath;
	}
	/*
	 * all of the pouring functions
	 * they return a NEW state with the state action in the function name
	 */
	State CtoA(){
		/**
		 * returns new state with action CtoA
		 */

		//pouring
		int pour = 0;
		if(c_ >= capA_){
			pour = capA_ - a_;

		}
		else {
			if(a_ + c_ > capA_){
				pour = capA_ - a_;
			}
			else{
				pour = c_;
			}
		}
		int C = c_ - pour;
		int A = a_ + pour;
		int B = b_;

		//string conversions
		string s;
		ostringstream convert;
		convert << pour;
		s = convert.str();

		//add the pour to the path
		string pathnew;
		if(pour ==1){
			pathnew = path_ + "Pour 1 gallon from C to A. ";
		}
		else{
			pathnew = path_ + "Pour " + s + " gallons from C to A. ";
		}

		State newS(A,B,C,pathnew, capA_, capB_, capC_);	//create new jug state

		//string conversions
		ostringstream converta;
		converta << newS.getA();
		string aa = converta.str();
		ostringstream convertb;
		convertb << newS.getB();
		string bb = convertb.str();
		ostringstream convertc;
		convertc << newS.getC();
		string cc = convertc.str();

		newS.setPath(pathnew+  "(" + aa + ", " + bb + ", " + cc + ")\n");	//extend the path

		return newS;
	}
	State CtoB(){
		/**
		 * returns new state with action CtoB
		*/
		int pour = 0;
		if(c_ >= capB_){
			pour = capB_ - b_;

		}
		else {
			if(c_+ b_> capB_){
				pour = capB_ - b_;
			}
			else {
				pour = c_;
			}
		}
		int C = c_ - pour;
		int B = b_ + pour;
		int A = a_;

		//string conversions
		string s;
		ostringstream convert;
		convert << pour;
		s = convert.str();
		string pathnew;
		if(pour == 1){
			pathnew = path_ + "Pour 1 gallon from C to B. ";
		}
		else{
			pathnew = path_ + "Pour " + s +  " gallons from C to B. ";
		}
		State newS(A,B,C,pathnew, capA_, capB_, capC_);	//create new jug state

		//string conversions
		ostringstream converta;
		converta << newS.getA();
		string aa = converta.str();
		ostringstream convertb;
		convertb << newS.getB();
		string bb = convertb.str();
		ostringstream convertc;
		convertc << newS.getC();
		string cc = convertc.str();

		newS.setPath(pathnew+  "(" + aa + ", " + bb + ", " + cc + ")\n"); //extend the path

		return newS;
	}
	State BtoA(){
		/**
		 * returns new state with action BtoA
		*/
		int pour = 0;
		if(b_ >= capA_){
			pour = capA_ - a_;

		}
		else {
			if(a_+ b_> capA_){
				pour = capA_ - b_;
			}
			else {
				pour = b_;
			}
		}
		int C = c_;
		int B = b_ - pour;
		int A = a_ + pour;

		//string conversions
		string s;
		ostringstream convert;
		convert << pour;
		s = convert.str();
		string pathnew;
		if(pour == 1){
			pathnew = path_ + "Pour 1 gallon from B to A. ";
		}
		else{
			pathnew = path_ + "Pour " + s +  " gallons from B to A. ";
		}

		State newS(A,B,C,pathnew, capA_, capB_, capC_);	//create new jug state

		//string conversions
		ostringstream converta;
		converta << newS.getA();
		string aa = converta.str();
		ostringstream convertb;
		convertb << newS.getB();
		string bb = convertb.str();
		ostringstream convertc;
		convertc << newS.getC();
		string cc = convertc.str();

		newS.setPath(pathnew+  "(" + aa + ", " + bb + ", " + cc + ")\n");	//extend the path

		return newS;
	}
	State BtoC(){
		/**
		 * returns new state with action BtoC
		*/
		int pour = 0;
		if(c_ + b_ >= capC_){
			pour = capC_ - c_;
		}
		else{
			pour = b_;
		}
		int C = c_ + pour;
		int B = b_ - pour;
		int A = a_;

		//string conversions
		string s;
		ostringstream convert;
		convert << pour;
		s = convert.str();
		string pathnew;
		if(pour ==1){
			pathnew = path_ + "Pour 1 gallon from B to C. ";
		}
		else{
			pathnew = path_ + "Pour " + s +  " gallons from B to C. ";
		}

		State newS(A,B,C,pathnew, capA_, capB_, capC_);	//create new jug state

		//string conversions
		ostringstream converta;
		converta << newS.getA();
		string aa = converta.str();
		ostringstream convertb;
		convertb << newS.getB();
		string bb = convertb.str();
		ostringstream convertc;
		convertc << newS.getC();
		string cc = convertc.str();

		newS.setPath(pathnew+  "(" + aa + ", " + bb + ", " + cc + ")\n");	//extend the path

		return newS;
	}
	State AtoB(){
		/**
		 * returns new state with action AtoB
		*/
		int pour = 0;
		if(a_ + b_ >= capB_){
			pour = capB_ - b_;
		}
		else{
			pour = a_;
		}
		int C = c_;
		int B = b_ + pour;
		int A = a_ - pour;

		//string conversions
		string s;
		ostringstream convert;
		convert << pour;
		s = convert.str();
		string pathnew;
		if(pour == 1){
			pathnew = path_ + "Pour 1 gallon from A to B. ";
		}
		else{
			pathnew = path_ + "Pour " + s +  " gallons from A to B. ";
		}

		State newS(A,B,C,pathnew, capA_, capB_, capC_);	//create new jug state

		//string conversions
		ostringstream converta;
		converta << newS.getA();
		string aa = converta.str();
		ostringstream convertb;
		convertb << newS.getB();
		string bb = convertb.str();
		ostringstream convertc;
		convertc << newS.getC();
		string cc = convertc.str();

		newS.setPath(pathnew+  "(" + aa + ", " + bb + ", " + cc + ")\n");	//extend the path

		return newS;
	}
	State AtoC(){
		/**
		 * returns new state with action AtoC
		*/
		int pour = 0;
		if(a_ + c_ >= capC_){
			pour = capC_ - c_;
		}
		else{
			pour = a_;
		}
		int C = c_ + pour;
		int B = b_;
		int A = a_ - pour;

		//string conversions
		string s;
		ostringstream convert;
		convert << pour;
		s = convert.str();
		string pathnew;
		if(pour == 1){
			pathnew = path_ + "Pour 1 gallon from A to C. ";
		}
		else{
			pathnew = path_ + "Pour " + s +  " gallons from A to C. ";
		}

		State newS(A,B,C,pathnew, capA_, capB_, capC_);	//create new jug state

		//string conversions
		ostringstream converta;
		converta << newS.getA();
		string aa = converta.str();
		ostringstream convertb;
		convertb << newS.getB();
		string bb = convertb.str();
		ostringstream convertc;
		convertc << newS.getC();
		string cc = convertc.str();

		newS.setPath(pathnew+  "(" + aa + ", " + bb + ", " + cc + ")\n");	//extend the path

		return newS;
	}

	//functions to check if a move is valid for specific action
	//a valid action must not overflow a jug or pour more water than is present
	bool checkCtoA(){
		if(a_ < capA_ && c_ > 0){
			return true;
		}
		else {
			return false;
		}
	}
	bool checkCtoB(){
		if(b_ < capB_ && c_ > 0){
				return true;
			}
			else {
				return false;
		}
	}
	bool checkBtoA(){
		if(a_ < capA_ && b_ > 0){
				return true;
			}
			else {
				return false;
		}
	}
	bool checkBtoC(){
		if(c_ < capC_ && b_ > 0){
				return true;
			}
			else {
				return false;
		}
	}
	bool checkAtoB(){
		if(b_ < capB_ && a_ > 0){
				return true;
			}
			else {
				return false;
		}
	}
	bool checkAtoC(){
		if(c_ < capC_ && a_ > 0){
				return true;
			}
			else {
				return false;
		}
	}
	bool checkEqual(State check){
		/**
		 * returns true if two jug states have the same a,b,and c values
		 *
		 * this function is not a true 'Equal' Check, it's purpose is only to verify the amount of water in each jug are equal. The other 4 elements to the jug are irrelevent to the purpose of this function
		 */
		if(a_ == check.getA() && b_ == check.getB() && c_ == check.getC()){
			return true;
		}
		else{
			return false;
		}
	}
	void print(){
		/**
		 * prints the path to get to the state
		 */
		cout << "Initial state. (" << "0" << ", " << "0" << ", " << capC_ << ")" << endl;
		cout << path_;
	}



private:
	//variable initialization
	int a_;
	int b_;
	int c_;
	string path_;
	int capA_;
	int capB_;
	int capC_;


};


State jugSolver(State start, State goal){
	/**
	 * the solving function
	 * performs a breadth first search starting from the start looking for the goal
	 * returns the answer state with full path if answer exists
	 * returns the start state and also prints no solution if answer does not exist
	 */

	bool array[100][100] = {{false}};	//create array
	queue<State> que;					//create que

	que.push(start);					//push start state to the queue
	array[start.getA()][start.getB()] = true;

	//main loop checks all options and then adds to the breadth first search pattern
	while(!que.empty()){
		State temp = que.front();
		if(temp.checkCtoA()){
			State newstate = temp.CtoA();
			if(array[newstate.getA()][newstate.getB()] == false){
				que.push(newstate);
				array[newstate.getA()][newstate.getB()] = true;
				if(goal.checkEqual(newstate)){
					return newstate;
				}
			}
		}
		if(temp.checkCtoB()){
			State newstate = temp.CtoB();
			if(array[newstate.getA()][newstate.getB()] == false){
				que.push(newstate);
				array[newstate.getA()][newstate.getB()] = true;
				if(goal.checkEqual(newstate)){
					return newstate;
				}
			}
		}
		if(temp.checkBtoA()){
			State newstate = temp.BtoA();
			if(array[newstate.getA()][newstate.getB()] == false){
				que.push(newstate);
				array[newstate.getA()][newstate.getB()] = true;
				if(goal.checkEqual(newstate)){
					return newstate;
				}
			}
		}
		if(temp.checkBtoC()){
			State newstate = temp.BtoC();
			if(array[newstate.getA()][newstate.getB()] == false){
				que.push(newstate);
				array[newstate.getA()][newstate.getB()] = true;
				if(goal.checkEqual(newstate)){
					return newstate;
				}
			}
		}
		if(temp.checkAtoB()){
			State newstate = temp.AtoB();
			if(array[newstate.getA()][newstate.getB()] == false){
				que.push(newstate);
				array[newstate.getA()][newstate.getB()] = true;
				if(goal.checkEqual(newstate)){
					return newstate;
				}
			}
		}
		if(temp.checkAtoC()){
			State newstate = temp.AtoC();
			if(array[newstate.getA()][newstate.getB()] == false){
				que.push(newstate);
				array[newstate.getA()][newstate.getB()] = true;
				if(goal.checkEqual(newstate)){
					return newstate;
				}
			}
		}
		que.pop();	//pop the que to move on after checking all options
	}
	cout << "No solution.";	//if nothing was returned during the loop then there is no answer
	return start;	//return start, just to return something, main checks for this
}


int main(int argc, char * const argv[]){
		/**
		 * main function
		 * checks all possible incorrect inputs
		 * then runs jug solver
		 * prints answer in format required for assignment
		 */

        istringstream iss;
        //any of the arguments is empty - failed to give an argument
        if(argv[1] == NULL || argv[2] == NULL || argv[3] == NULL|| argv[4] == NULL || argv[5] == NULL || argv[6] == NULL)
                {
                cout<< "Usage: ./waterjugpuzzle <cap A> <cap B> <cap C> <goal A> <goal B> <goal C>";
                                cout<<flush;
                                return 1;
                }
        if(argv[7])	//too many arguments
        {
                cout<< "Usage: ./waterjugpuzzle <cap A> <cap B> <cap C> <goal A> <goal B> <goal C>";
                return 1;
        }
        else if(atoi(argv[1]) <= 0)	//arguments are less than 0
                {
                        cout << "Error: Invalid capacity "<<"'" << argv[1] <<"'"<<" for jug A." << endl;
                        cout<<flush;
                        return 0;
                }
        else if(atoi(argv[2]) <= 0)
        {
                cerr << "Error: Invalid capacity "<<"'" << argv[2] <<"'"<<" for jug B." << endl;
                        return 1;
        }
        else if(atoi(argv[3]) <= 0)
                {
                        cerr << "Error: Invalid capacity "<<"'" << argv[3] <<"'"<<" for jug C." << endl;
                        return 1;
                }

        else if(atoi(argv[4]) < 0)
        {
                cerr << "Error: Invalid goal" <<" '"<<argv[4]<<"' " << "for jug A."<<endl;
                return 1;
        }
        else if(atoi(argv[5]) < 0)
                {
                        cerr << "Error: Invalid goal" <<" '"<<argv[5]<<"' " << "for jug B."<<endl;
                        return 1;
                }
        else if(atoi(argv[6]) < 0)
                {
                        cerr << "Error: Invalid goal" <<" '"<<argv[6]<<"' " << "for jug C."<<endl;
                        return 1;
                }

        //arguments are non integers
        stringstream ssv1(argv[1]);
        stringstream ssv2(argv[2]);
        stringstream ssv3(argv[3]);
        stringstream ssv4(argv[4]);
        stringstream ssv5(argv[5]);
        stringstream ssv6(argv[6]);
        int num1;
        int num2;
        int num3;
        int num4;
        int num5;
        int num6;
        if(!(ssv1 >> num1))
        {
                cerr << "Error: Invalid capacity "<< "'"<< argv[1] <<"'"<<" for jug A." << endl;
                return 1;
        }
        else if(!(ssv2 >> num2))
        {
                cerr << "Error: Invalid capacity "<< "'"<< argv[2] <<"'"<<" for jug B." << endl;
                return 1;
        }
        else if(!(ssv3 >> num3))
        {
                cerr << "Error: Invalid capacity "<<"'" << argv[3] <<"'"<<" for jug C." << endl;
                return 1;
        }
        else if(!(ssv4 >> num4))
        {
                cerr<< "Error: Invalid goal"<<" '"<<argv[4] << "' "<<"for jug A."<<endl;
                return 1;
        }
        else if(!(ssv5 >> num5))
        {
                cerr<< "Error: Invalid goal"<<" '"<<argv[5] << "' "<<"for jug B."<<endl;
                return 1;
        }
        else if(!(ssv6 >> num6))
        {
                cerr<< "Error: Invalid goal "<<"'"<<argv[6] << "'"<<" for jug C."<<endl;
                return 1;
        }


        else if(atoi(argv[1]) < atoi(argv[4]))
        {
                cerr << "Error: Goal cannot exceed capacity of jug A.";
                return 1;
        }
        else if(atoi(argv[2]) < atoi(argv[5]))
        {
                cerr << "Error: Goal cannot exceed capacity of jug B.";
                return 1;
        }
        else if(atoi(argv[3]) < atoi(argv[6]))
        {
                cerr << "Error: Goal cannot exceed capacity of jug C.";
                return 1;
        }

        if(atoi(argv[3]) != (atoi(argv[4]) + atoi(argv[5]) + atoi(argv[6]))){
        	cerr << "Error: Total gallons in goal state must be equal to the capacity of jug C.";
        	return 1;
        }
        //create starting and ending states from inputs
	//the start is always 0 0 (MAX of C)
	//ex. if jug arangment is 3 5 8 then the starting state is 0 0 8
        State starting(0,0,atoi(argv[3]), "", atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
        State goal(atoi(argv[4]),atoi(argv[5]),atoi(argv[6]), "", atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));

        if(starting.checkEqual(goal)){
        	starting.print();
        	return 0;
        }

        State answer = jugSolver(starting, goal);	//run jugsolver
        if(answer.checkEqual(starting)){			//no answer case
        	return 0;
        }
        else{
        	answer.print();							//print answer
        }
        return 0;
}
