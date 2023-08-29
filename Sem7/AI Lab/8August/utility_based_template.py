import random

class SimpleVacuumEnvironment:
    def __init__(self):
        self.rooms = {'Room A': 'Clean', 'Room B': 'Dirty'}
        self.agent_location = random.choice(['Room A', 'Room B'])

    def is_dirty(self, room):
        return self.rooms[room] == 'Dirty'

    def clean(self, room):
        self.rooms[room] = 'Clean'

    def move_agent(self, room):
        self.agent_location = room

    def display(self):
        print("Room Status:")
        for room, status in self.rooms.items():
            print(f"{room}: {status}")
        print(f"Vacuum Cleaner Location: {self.agent_location}")
        print()

class UtilityBasedVacuumAgent:
    def __init__(self, environment):
        self.environment = environment
        self.utilities = {'Room A': 0, 'Room B': 0}

    def calculate_utilities(self):
        for room in self.utilities:
            if self.environment.is_dirty(room):
                self.utilities[room] = -1
            else:
                self.utilities[room] = 1

    def decide_action(self):
        current_room = self.environment.agent_location
        other_room = "Room A" if current_room == "Room B" else "Room B"
        if self.utilities[current_room] < self.utilities[other_room]:
            return "Clean"
        else:
            return "Move"

    def act(self):
        action = self.decide_action()

        if action == "Clean":
            current_room = self.environment.agent_location
            self.environment.clean(current_room)
            print(f"Agent cleaned {current_room}.")
        else:
            current_room = self.environment.agent_location
            other_room = "Room A" if current_room == "Room B" else "Room B"
            self.environment.move_agent(other_room)
            print(f"Agent moved from {current_room} to {other_room}.")

# Example usage
env = SimpleVacuumEnvironment()
env.display()
agent = UtilityBasedVacuumAgent(env)

for x in range(5):
    agent.calculate_utilities()
    print(f"Utility Value = {agent.utilities}")
    agent.act()
    env.display()