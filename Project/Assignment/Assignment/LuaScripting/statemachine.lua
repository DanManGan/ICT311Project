-------------------------------------------------------------------------------

-- create the idle state

-------------------------------------------------------------------------------
state_idle = {}


state_idle["Enter"] = function(NPC)


  

end


state_idle["Execute"] = function(NPC)

--player:getFSM():setCurrentState(state_global)
--player:getFSM():changeState(state_global)
--player:setCurrentState(state_global)
	NPC:WaypointFollow()
	print ("idle execute called")


end

  
state_idle["Exit"] = function(NPC)



end

