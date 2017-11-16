#pragma once

#include "System.h"
#include "Message.h"
#include <list>


class Display;

class Engine
{
public:
	Engine();

	void SendMessage(Message msg);
private:
	bool running = true;
	void Loop();
	void Update();

	Display* m_display = nullptr;

#define F_MESSAGE_OBSERVER (1<<0)
	//00000001
#define F_UPDATABLE (1<<1)
	//00000010
#define F_INITIALIZABLE (1<<2)
	//00000100

	bool CreateSystem(System* _system, int _flag);
	std::list<System*> m_systems;
		
	template <typename T>
	T GetListElementAtIndex(std::list<T> _list, int _index)
	{
		std::list<T>::iterator it = _list.begin();
		for (auto i = 0; i < _index; i++) {
			++it;
		}
		return *it;
	}
};
