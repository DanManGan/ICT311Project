
/** 
  * @class Waypoint
  * @brief AI waypoints for object movement
  * 
  * Detailed
  * 
  * 
  * @param vectorType: vectorType type variable used for template in Waypoint class for templated class
  * 
  * 
  * @author Hong Xie??
  * @version 00
  * @date 
  * @status 
  * 
  * @author Justin Pettit
  * @version 01
  * @date 02.06.15
  * @status under construction
  * 
  * @todo 
  * 
  * @bugs 
  */ 

#ifndef WAYPOINT_H
#define WAYPOINT_H

#include <vector>
#include <iostream>

template <class vectorType>
class Waypoint
{
public:
	
	/** 
	  * @brief add waypoint
	  * @warning None
	  * 
	  * Detail
	  * 
	  * @param wayPt: const vectorType type variable in Waypoint class for waypoint to add
	  * 
	  * @pre 
	  * @post 
	  */ 
	void AddWaypoint(const vectorType& wayPt);

	/** 
	  * @brief gets waypoint
	  * @warning None
	  * 
	  * Detail
	  * 
	  * @param waypointNo: unsigned short type variable in Waypoint class for waypoint to get
	  * @return vectorType value for waypoint
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	vectorType GetWaypoint(unsigned short waypointNo) const;

	/** 
	  * @brief get n umber of waypoints
	  * @warning None
	  * 
	  * Detail
	  * 
	  * @return int value for number of waypoints
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	int GetNumWaypoints(){return (int)waypoints.size();}

	/** 
	  * @brief clears all waypoints
	  * @warning None
	  * 
	  * Detail
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	void ClearAllWaypoints();

	/** 
	  * @brief overload = operator
	  * @warning None
	  * 
	  * Detail
	  * 
	  * @param wp: const Waypoint<vectorType type variable in Waypoint class
	  * @return const Waypoint<vectorType>& value for waypoints
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const Waypoint<vectorType>& operator=(const Waypoint<vectorType> &wp);

	/** 
	  * @brief overloadded ostream operator
	  * @warning None
	  * 
	  * Detail
	  * 
	  * @param os: ostream type variable in Waypoint class 
	  * @param wp: Waypoint<vectorType type variable in Waypoint class 
	  * @return ostream & value 
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
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

	/** 
	  * @brief vector to store waypoints
	  * @warning None
	  * 
	  * Detail
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	std::vector<vectorType> waypoints;

private:
	//vector<vectorType> waypoints;
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