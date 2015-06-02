#ifndef WAYPOINT_H
#define WAYPOINT_H

#include <vector>
#include <iostream>

template <class vectorType>
class Waypoint
{
private:
	//vector<vectorType> waypoints;
public:
	std::vector<vectorType> waypoints;
	void AddWaypoint(const vectorType& wayPt);
	vectorType GetWaypoint(unsigned short waypointNo) const;
	int GetNumWaypoints(){return (int)waypoints.size();}
	void ClearAllWaypoints();
	const Waypoint<vectorType>& operator=(const Waypoint<vectorType> &wp);

	friend ostream& operator<<(ostream& os, Waypoint<vectorType> &wp)
	{
	  os << "Waypoints" << std::endl;
	    for(int i=0;i<wp.waypoints.size();i++)
	    {
		  os << i <<" "<< wp.waypoints[i].x << " " << 
			  wp.waypoints[i].y << " " << wp.waypoints[i].z  << std::endl;
	    }
     return os;
	}
};


template <class vectorType>
void Waypoint<vectorType>::AddWaypoint(const vectorType& wayPt)
{
	waypoints.push_back(wayPt);
}

template <class vectorType>
vectorType Waypoint<vectorType>::GetWaypoint(unsigned short waypointNo) const
{
 vectorType v;

	if(waypointNo >=0 && waypointNo < waypoints.size())
	{
		v=waypoints[waypointNo];
	}
 return v;
}

template <class vectorType>
void Waypoint<vectorType>::ClearAllWaypoints()
{

	if(waypoints.size()>0)
	{
		waypoints.clear();
	}
}

template <class vectorType>
const Waypoint<vectorType>& Waypoint<vectorType>::operator=(const Waypoint<vectorType> &wp)
{
	ClearAllWaypoints();
	for(int i=0;i<(int)wp.waypoints.size();i++)
	  {
		  waypoints.push_back(wp.waypoints[i]);
	  }
	return *this;
}


#endif