#pragma once

#include <chrono>
#include <iostream>

using namespace std;

class TimeManager
{
public:
	void StartTimer()
	{
		TimeStart = chrono::high_resolution_clock::now();
	}

	void EndTimer()
	{
		TimeEnd = chrono::high_resolution_clock::now();
		DeltaTime = chrono::duration<float, milli>(TimeEnd - TimeStart).count();
	}
	
	float GetDeltaTime()
	{
		return DeltaTime;
	}

	void PrintFPS()
	{
		if(DeltaTime != 0)
		{
			float fps = 1.0f / (DeltaTime/ 1000);
			cout << "Current FPS: " << fps << endl;
		}
	}

private:
	
	 float DeltaTime = 0;
	 chrono::steady_clock::time_point TimeStart;
	 chrono::steady_clock::time_point TimeEnd;
};
