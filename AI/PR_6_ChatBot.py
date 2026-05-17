# Simple Rule-Based Chatbot

while True:

    user = input("You: ").lower()

    # Rules
    if user == "hello":
        print("Bot: Hi!")

    elif user == "how are you":
        print("Bot: I am fine.")

    elif user == "what is your name":
        print("Bot: My name is ChatBot.")

    elif user == "bye":
        print("Bot: Goodbye!")
        break

    else:
        print("Bot: I don't understand.")