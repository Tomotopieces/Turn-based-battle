#include"BuffList.h"
#include"BuffEffectList.h"

BuffList & BuffList::operator=(BuffList & copy)
{
	buffList = copy.buffList;
}

bool BuffList::Exist(Buff & buff)
{
	for (auto it = buffList.begin(); it != buffList.end(); ++it) {
		if ((*it) == buff)
			return true;
	}
	return false;
}

std::vector<Buff>::iterator  BuffList::Locate(Buff & buff)
{
	for (auto it = buffList.begin(); it != buffList.end(); ++it) {
		if ((*it) == buff)
			return it;
	}
	return buffList.end();
}

BuffList & BuffList::Get(Buff & buff)
{
	if (Exist(buff)) {
		auto temp = Locate(buff);
		if (temp->Stackable())
			temp->update(buff.Level());
	}
	else {
		buffList.push_back(buff);
	}
}

BuffList & BuffList::Delete(Buff & buff)
{
	auto temp = Locate(buff);
	if (temp != buffList.end())
		buffList.erase(temp);
	return *this;
}

Buff Lost("Lost", false, false, NOEFFECT);
Buff Normal("Normal", false, false, NOEFFECT);
Buff CantTreat("CantTreat", false, false, NOEFFECT);
Buff Wound("Wound", true, false, WOUND);
