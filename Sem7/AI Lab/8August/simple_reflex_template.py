import random

class SimpleVacuumEnvironment():
    def __init__(self):
	    # Initialize rooms,room_status,agent_location
	    # 1 means clean and 0 means dirty
        self.rooms = {'A': '0','B':'1'}
        self.rooms['A'] = random.randint('0','1')
        self.rooms['B'] = random.randint('0','1')
        self.vacuumLocation = random.choice('A','B')
        

    def is_dirty(self, room):
        # Returns if the room is dirty or not
        if self.rooms[room]=='1' : 
            return False
        else:
            return True

    def clean(self, room):
        # Returns if the room is clean or not
        if self.rooms[room]=='1' :
            return True
        else :
            self.rooms[room]=1
            return False    

    def move_agent(self, room):
        # Assigns the agent_location with room
        self.vacuumLocation = room      	

    def display(self):
        # Display the current state of the environment.
        print("Status of All Rooms:")
        for Room,Status in self.rooms.items() :
            print(f"{Room} : {Status}")
        print(f"Vacuum Location: {self.vacuumLocation}")
        print()


class SimpleReflexVacuumAgent(SimpleVacuumEnvironment ):

    def __init__(self, environment):
        self.environment = environment
        self.model = {}

    def perceive(self):
        # The agent perceives the current room it is in and whether the room is dirty or not.
        currentRoom = self.environment.vacuumLocation
        dirtStatus = self.environment.is_dirty(currentRoom)
        if dirtStatus == 1 :
            print(f"{currentRoom} is Dirty")
        else :
            print(f"{currentRoom} is Clean")

    def decide_action(self,dirtStatus):
        #  Based on the dirt status, the agent decides whether to clean or move. If the room is dirty, it chooses to clean; otherwise, it chooses to move.
        currentRoom = self.environment.vacuumLocation
    

    def act(self):
        # The agent performs the chosen action. If it decides to clean, 
	    # it cleans the room and updates the environment's status. 
	    # If it decides to move, it moves to the other room and updates its location.
        currentRoom,dirtStatus = self.perceive()
        action = self.decide_action(dirtStatus)

        if action == '1' :
            self.environment.clean(currentRoom)
            print(f"Vaccum cleaned {currentRoom}")
        else :
            otherRoom = 'A' if currentRoom == 'B' else 'B'
            self.environment.move_agent(otherRoom)
            print(f"Vacuum moved from {currentRoom} to {otherRoom}")

# Example usage
env = SimpleVacuumEnvironment()
env.display()
agent = SimpleReflexVacuumAgent(env)
while True :
    agent.act()
    env.display()
