import random

class SimpleVacuumEnvironment:
    def __init__(self):
	    # Initialize rooms,room_status,agent_location
        self.rooms = {'A' : '0', 'B' : '0'}
        self.rooms['A'] = random.choice(['0','1'])
        self.rooms['B'] = random.choice(['0','1'])
        self.vacuumLocation = random.choice(['A','B'])

    def is_dirty(self, room):
        # Returns if the room is dirty or not
        return self.rooms[room] == '0'

    def clean(self, room):
        # Returns if the room is clean or not
        self.rooms[room] = '1'

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


class ModelBasedReflexVacuumAgent:
    def __init__(self, environment):
        # Initialize environment and model
        self.environment = environment
        self.model = {}

    def perceive(self):
        # Perceive and return the current room and dirt status
        currentRoom = self.environment.vacuumLocation
        dirtStatus = self.environment.is_dirty(currentRoom)
        return currentRoom,dirtStatus

    def update_model(self, room):
        # The agent updates its model of the environment by marking 
	    # the current room as clean in its model.
        self.model[room] = '1'

    def decide_action(self, dirt_status):
        # the agent decides whether to clean or move based on its perception and model. 
        # If the room is dirty in the actual environment, it chooses to clean. 
        # If the room is clean in the actual environment but marked as dirty in the model, 
        # it still chooses to clean based on the model. Otherwise, it chooses to move.
        currentRoom = self.environment.vacuumLocation
        if dirt_status :
            return '1'
        elif self.model.get(currentRoom) == '0' :
            return '1'
        else :
            return '2'

    def act(self):
        # The agent performs the chosen action. 
        # If it decides to clean, it cleans the room in both the actual environment 
        # and its model, and updates the model. If it decides to move, it moves to 
        # the other room and updates its location.
        currentRoom,dirtStatus = self.perceive()
        action = self.decide_action(dirtStatus)

        if action == '1' :
            self.environment.clean(currentRoom)
            self.update_model(currentRoom)
            print(f"Vacuum cleaned {currentRoom}")
        else :
            otherRoom = 'A' if currentRoom == 'B' else 'B'
            self.environment.move_agent(otherRoom)
            print(f"Vacuum moved from {currentRoom} to {otherRoom}")

# Example usage
env = SimpleVacuumEnvironment()
env.display()
agent = ModelBasedReflexVacuumAgent(env)
for _ in range(3):
    agent.act()
    env.display()