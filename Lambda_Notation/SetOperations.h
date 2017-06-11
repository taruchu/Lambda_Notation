#pragma once

#include <iostream>
#include <vector> 
#include <typeinfo> 

using namespace std;
/*
I need to create a set of functions that are extensions of the std::vector<T> type so that
I can perform set operations on the list using chaining. They should all take a delegate as parameter.
For example:
	vector<int> lst = new vector<int>();
	lst.Add(2);
	lst.Add(3);
	lst.Add(4);
	
	list<int> lst2 = lst
						.Select(a => a)
						.Where(b => b > 2);

I need to implement these set operations:
(1) Select<T , S>( func(typeof(this), object) ) ???
(2) FindAll<T , T> (func(typeof(this), bool))  this will need to return each element if they pass a predicate
(3) ??? Where
(4) Union<list<T> , list<T>>
(5) Intersect<list<T> , list<T>>
(6) LeftOuterJoin<list<T> , list<T>>
(7) RightOuterJoin<list<T> , list<T>>
(8) Top<T , T>(int n)  will get the top n elements
(9) Bottom<T , T>(int n) will get the bottom n elements
  
*/

namespace setoperations
{
	class __declspec(dllexport) OutOfRangeExc : exception
	{ 
		private:
			char* message;
		public:
			OutOfRangeExc(char* msg = NULL)
			{
				SetMessage((msg != NULL) ? msg : "Application Error.");
				throw exception(GetMessage());
			}
			char*  GetMessage();
			void SetMessage(char* msg);
	};

	template<class T>
	class  __declspec(dllexport) SetVector  
	{
		private:
			typename vector<T>::iterator iter;//TODO: Make this public and or create a public print to console method to dump the set to the console.
	
		public:
			vector<T> set;
			template<class U>
			static SetVector<U> Select(vector<T> vect, U(*selectFunc)(T element));
			SetVector FindAll(bool(*predicate)(T element));
			//TODO:
			/*SetVector Union(vector<T> lst1, vector<T> lst2, bool(*predicateJoins)(T element1, T element2));
			SetVector Intersection(vector<T> lst1, vector<T> lst2, bool(*predicateJoins)(T element1, T element2));
			SetVector LeftOuterJoin(vector<T> lst1, vector<T> lst2, bool(*predicateJoins)(T element1, T element2));
			SetVector RightOuterJoin(vector<T> lst1, vector<T> lst2, bool(*predicateJoins)(T element1, T element2));
			SetVector Top(int n);
			SetVector Bottom(int n);*/

			SetVector() {};
			SetVector(int reserve) 
			{
				set.reserve(reserve);
			};
			~SetVector() {};
	};
	
	
	template<class T>
	template<class U>
	inline SetVector<U> SetVector<T>::Select(vector<T> vect, U(*selectFunc)(T element))
	{  
		//TODO: Add try/catch
		SetVector<U> newSet;
		for (int i = 0; i < vect.size(); i++)
		{
			U result = (*selectFunc)(vect[i]);
			newSet.set.push_back(result);
		}
		return newSet;
	}

	template<class T>
	inline SetVector<T> SetVector<T>::FindAll(bool(*predicate)(T element))
	{
		//TODO: Add try/catch
		SetVector<T> newSet;
		for (int i = 0; i < set.size(); i++)
		{
			if ((*predicate)(set[i]) == true)
				newSet.set.push_back(set[i]);
		}
		return newSet;
	}

};