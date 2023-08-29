import random

class SimpleVacuumEnvironment:
    def __init__(self):
	    # Initialize rooms,room_status,agent_location
        self.rooms = {'A':'0','B':'0'}
        self.rooms['A'] = random.choice(['0','1'])
        self.rooms['B'] = random.choice(['0','1'])
        self.vacuumLocation = random.choice(['0','1'])

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
        print('Status of All Rooms:')
        for Room,Status in self.rooms.items() :
            print(f"{Room}: {Status}")
        print(f"Vacuum cleaner location: {self.vacuumLocation}")
        print()


class GoalBasedVacuumAgent:
    def __init__(self, environment):
        # Initialize environment and goals
        self.environment = environment
        self.goals = []
	
    def set_goal(self, goal):
        # Set goals with actions and priorities
        self.goals.append(goal)

    def prioritize_goals(self):
        # Sort goals based on priority criteria
        self.goals.sort(key=lambda x:x[1])

    def perceive(self):
        # Perceive and return the current room and dirt status.
        currentRoom = self.environment.vacuumLocation
        dirtStatus = self.environment.is_dirty(currentRoom)
        return currentRoom,dirtStatus

    def decide_action(self, dirt_status):
        # The agent decides on the action to take based on the highest	
        # priority goal. If there are no goals, the agent will have no action.
        if self.goals :
            return self.goals[0][0]
        return None

    def act(self):
        # The agent performs the decided action. If the action is to clean, 
        # it cleans the room. If the action is to move, it moves to the target room.
        currentRoom,dirtStatus = self.perceive()
        action = self.decide_action(dirtStatus)

        if action == '1': 
            self.environment.clean(currentRoom)
            print(f"Vacuum cleaned {currentRoom}")
        elif action =='2' :
            otherRoom = 'A' if currentRoom == 'B' else 'B'
            self.environment.move_agent(otherRoom)
            print(f"Vacuum moved from {currentRoom} to {otherRoom}")
        else :
            print('Vacuum has no action')


# Example usage
env = SimpleVacuumEnvironment()
agent = GoalBasedVacuumAgent(env)
agent.set_goal(('Clean', 1))  # Priority 1: Clean the room
agent.set_goal(('Move', 2))  # Priority 2: Move to room B
agent.prioritize_goals()
for _ in range(5):
    agent.act()
    env.display()