-------------------------------------------------------------------------------

-- create the flee state

-------------------------------------------------------------------------------
state_flee = {}


state_flee["enter"] = function(player)



end


state_flee["execute"] = function(player)



end

  
state_flee["exit"] = function(player)


end

state_flee["onMessage"] = function(player,msg)


end

-------------------------------------------------------------------------------

-- create the global state

-------------------------------------------------------------------------------
state_global = {}


state_global["enter"] = function(player)



end


state_global["execute"] = function(player)



end

  
state_global["exit"] = function(player)



end

state_global["onMessage"] = function(player,msg)

return false

end

-------------------------------------------------------------------------------

-- create the idle state

-------------------------------------------------------------------------------
state_idle = {}


state_idle["enter"] = function(player)


  

end


state_idle["execute"] = function(player)

--player:getFSM():setCurrentState(state_global)
--player:getFSM():changeState(state_global)
--player:setCurrentState(state_global)




end

  
state_idle["exit"] = function(player)



end

state_idle["onMessage"] = function(player,msg)



end

-------------------------------------------------------------------------------

-- create the patrol state

-------------------------------------------------------------------------------
state_patrol = {}


state_patrol["enter"] = function(player)

  player:setCurwayPointNo(0)
  

end


state_patrol["execute"] = function(player)

  player:waypointFollow()
    if(player:watchForEnemy()) then
       a=vector2D()
       a:set(400,400)
       player:sendMessage(0,player:getPlayerID(),1,1,a)
       player:getFSM():changeState(state_chase)

      
    end

end

  
state_patrol["exit"] = function(player)

  print ("exit patrol state")

end

state_patrol["onMessage"] = function(player,msg)
 if(msg.msg==1 and player:getPlayerID()==1) then
     print("msg recd")
     player:setEnemyTarget(msg.extraInfo:getX(),msg.extraInfo:getY())
     player:getFSM():changeState(state_chase)
   --  player:moveToEnemy()
   end

end

-------------------------------------------------------------------------------

-- create the chase state

-------------------------------------------------------------------------------
state_chase = {}


state_chase["enter"] = function(player)


  

end


state_chase["execute"] = function(player)


player:moveToEnemy()

end

  
state_chase["exit"] = function(player)



end

state_chase["onMessage"] = function(player,msg)



end