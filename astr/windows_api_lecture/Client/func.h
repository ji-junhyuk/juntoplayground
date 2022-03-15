#pragma once

class CObject;

void CreateObject(CObject* _pObj, GROUP_TYPE _eGroup);
void DeleteObject(CObject* _pObj);
void ChangeScene(SCENE_TYPE _eNext);

template<typename T>
void Safe_Delete_Vec(vector<T>& _vec)
{
	for (size_t idx = 0; idx < _vec.size(); ++idx)
	{
		if (_vec[idx] != nullptr)
		{
			delete _vec[idx];
		}
	}
	_vec.clear();
}

template<typename T1, typename T2>
void Safe_Delete_Map(map<T1, T2>& _map)
{
	typename map<T1, T2>::iterator iter = _map.begin();

	for (; iter != _map.end(); ++iter)
	{
		if (iter->second != nullptr)
			delete iter->second;
	 }
	_map.clear();
}