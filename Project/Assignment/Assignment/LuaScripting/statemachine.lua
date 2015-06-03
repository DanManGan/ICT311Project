

-- Animation States
--	  STAND = 0
--	  RUN = 1
-- 	  ATTACK = 2
--    PAIN_A = 3
--    PAIN_B = 4
--    PAIN_C = 5
--    JUMP = 6
--    FLIP = 7
--    SALUTE = 8
--    FALLBACK = 9
--    WAVE = 10
--    POINT_AT = 11
--    CROUCH_STAND = 12
--    CROUCH_WALK = 13
--    CROUCH_ATTACK = 14
--    CROUCH_PAIN = 15
--    CROUCH_DEATH = 16
--    DEATH_FALLBACK = 17
--    DEATH_FALLFORWARD = 18
--    DEATH_FALLBACKSLOW = 19
--    BOOM = 20



-------------------------------------------------------------------------------

-- create the idle state

-------------------------------------------------------------------------------
state_idle = {}


state_idle["Enter"] = function(NPC)
 print ("idle enter called")
	NPC:SetAnimationLua(8)
	--NPC:SetCurWaypoint(2)
 

end


state_idle["Execute"] = function(NPC)

--player:getFSM():setCurrentState(state_global)
--player:getFSM():changeState(state_global)
--player:setCurrentState(state_global)
	--NPC:WaypointFollow()
	print ("idle execute called")
	if(NPC:IdleStateDone()) then
		NPC:GetFSM():ChangeState(state_patrol)
		--print ("idle execute complete")
	end

end

  
state_idle["Exit"] = function(NPC)



end


-------------------------------------------------------------------------------

-- create the patrol state

-------------------------------------------------------------------------------
state_patrol = {}


state_patrol["Enter"] = function(NPC)

	--NPC:SetCurWaypoint(0)
	NPC:SetAnimationLua(1)

end


state_patrol["Execute"] = function(NPC)

  --player:waypointFollow()
  --  if(player:watchForEnemy()) then
  --     a=Vector3D()
  --     a:Set(200,200,200)
  --     player:sendMessage(0,player:getPlayerID(),1,1,a)
  --     player:getFSM():changeState(state_chase)   
  --  end
	if (NPC:GetWaypointCycles() == 2) then
		NPC:GetFSM():ChangeState(state_idle)
		NPC:SetWaypointCycles(0)
	else
		NPC:WaypointFollow()
	end

	
end

  
state_patrol["Exit"] = function(NPC)

  --print ("exit patrol state")

end


-------------------------------------------------------------------------------

-- create the global state

-------------------------------------------------------------------------------
state_global = {}


state_global["Enter"] = function(NPC)



end


state_global["Execute"] = function(NPC)

	if(NPC:Collision()) then
		print("stuck in global")
		NPC:GetFSM():ChangeState(state_collision)
	end

end

  
state_global["Exit"] = function(NPC)



end


-------------------------------------------------------------------------------

-- create the collision state

-------------------------------------------------------------------------------
state_collision = {}


state_collision["Enter"] = function(NPC)

	NPC:SetAnimationLua(9)

end


state_collision["Execute"] = function(NPC)
	print ("collision execute")
	if(NPC:IdleStateDone()) then
		NPC:GetFSM():RevertToPreviousState()
		print ("collision execute complete")
	end
		

end

  
state_collision["Exit"] = function(NPC)

	print ("collision exit called")

end
