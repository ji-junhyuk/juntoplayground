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