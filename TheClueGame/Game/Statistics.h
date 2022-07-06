#ifndef  _Statistics_
#define  _Statistics_

#include "Board.h"
#include <conio.h>
#include <fstream>
#include<vector>
#include <iostream>
using namespace std;


template<typename T, int N = 1>
class Arr {
	T m_data[N];
public:
	Arr(const T& initializer = 0) {
		for (int i = 0; i < N; i++)
			m_data[i] = initializer;
	};
	Arr(initializer_list<T> values) {
		copy(values.begin(), values.end(), m_data);
	};
	~Arr() {};

	T operator[](unsigned index) const {
		return m_data[index];
	}
	T& operator[](int index) {
		return m_data[index];
	};
	Arr<T,N>& operator=(const Arr<T,N>& v) {
		for (int i = 0; i < N; i++)
			m_data[i] = v.m_data[i];
		return *this;
	}
	void operator=(initializer_list<T> values) {
		copy(values.begin(), values.end(), m_data);
	}
	T& operator=(const T& t) {
		for (int i = 0; i < N; i++)
			m_data[i] = t;
	}
	Arr<T,N>& operator+=(const Arr<T,N>& v) {
		for (int i = 0; i < N; i++)
			m_data[i] += v.m_data[i];
		return *this;
	}

	void swapIndex(int i1, int i2) {
		T tmp;
		tmp = m_data[i1];
		m_data[i1] = m_data[i2];
		m_data[i2] = tmp;
	}
	float sum(int i_s = 0, int i_e = N) {
		T sum = 0;
		for (int i = i_s; i < i_e; i++)
			sum += m_data[i];
		return sum;
	}
	float avg(int i_s = 0, int i_e = N) {
		return (float)sum(i_s, i_e) / (i_e - i_s);	//T must be such that the conversation will be legal
	}
	T get_max() {
		T tmp = 0;
		for (int i = 0; i < N; i++)
			if (tmp > m_data[i])
				tmp = m_data[i];
		return tmp;
	}
};

template <typename T, int N>
ostream& operator<<(ostream &os, const Arr<T, N>& v)
{
	for (int i = 0; i < N; i++)
		os << v[i] << ' ';
	return os;
}

template<typename T, int N>
ofstream& operator<<(ofstream &os, const Arr<T, N>& v)
{
	int i;
	for (i = 0; i < N - 1; i++)
		os << v[i] << ' '; 
	return os;
}

//template<typename T, int N>					////causing problems for some reasons  
//ifstream& operator>>(ifstream &os, const Arr<T, N>& v)
//{
//	for (int i = 0; i < N; i++)
//		os >> v[i];
//	return os;
//}


class Statistics {
	Arr<int, 6> player_wined = 0;
	Arr<int, 6> player_wrong_acc = 0;			
	Arr<int, 6> player_chosen = 0;				
	Arr<int, 9> room_visits = 0;
	Arr<int, 6> Player_Secret_Passage = 0;
	Arr<int, 6> player_throw_dice = 0;
	Arr<int, 6> player_sum_throw = 0;

	int games_stoped = 0;
	int player_count = 0;						
	friend void game(Board& board, MurderEnvelope& envelope, int& p_num, Statistics& stat);
	friend void start();
public:
	friend ifstream& operator>>(ifstream& f, Statistics& p);
	int get_games_stoped() const { return games_stoped; };
	int get_player_count() const { return player_count; };
	Arr<int, 6> get_player_chosen() const { return player_chosen; };
	Arr<int, 6> get_player_wrong_acc() const { return player_wrong_acc; };
	Arr<int, 6>  get_player_wined() const { return player_wined; };
	Arr<int, 9> get_room_visits() const{ return room_visits; };
	Arr<int, 6> get_Secret_Passage() const { return Player_Secret_Passage; };
	Arr<int, 6> get_player_throw_dice() const { return player_throw_dice; };
	Arr<int, 6> get_player_sum_throw() const { return player_sum_throw; };
	
	void save();
	void load();
	
};

void calculate_stats();


#endif