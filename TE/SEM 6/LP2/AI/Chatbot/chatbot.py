import random

# Dictionary of predefined responses
responses = {
    "greeting": ["Hello!", "Hi!", "Welcome to our online store! How can I assist you?"],
    "farewell": ["Thank you for visiting our store. Have a great day!", "Goodbye! Come back soon!"],
    "thanks": ["You're welcome!", "No problem!", "Glad to help!"],
    "product_inquiry": ["Sure, let me check that for you.", "Certainly! I'll find the information about that product."],
    "order_status": ["Please provide your order number, and I'll check its status.", "I can help you with that. What's your order number?"],
    "shipping_status": ["To track your order, please provide your order number.", "I'll assist you with the shipping status. What's your order number?"],
    "product_category": ["We offer a wide range of product categories, including shoes, shirts, and trousers.", "Our store has products in different categories such as shoes, shirts, and trousers."],
    "shoes_range":["Sports shoes range from 900-5,000\n Sneakers range: 1,000-4,000"],
    "trouser_range":["Chinos: 1,200-3,000\nFormals: 1,500-4,000"],
    "shirt_range":["Formals: 2,000-5,000\nParty Wear: 1,000-4,000"],
    "default": ["I'm sorry, I didn't understand. Could you please rephrase that?", "I'm still learning. Can you provide more details?"]
}

# Function to generate a response based on user input
def generate_response(user_input):
    user_input = user_input.lower()

    if "hello" in user_input or user_input=="hi":
        return random.choice(responses["greeting"])
    elif "goodbye" in user_input or "bye" in user_input:
        return random.choice(responses["farewell"])
    elif "thank" in user_input:
        return random.choice(responses["thanks"])
    elif "shipping" in user_input:
        return random.choice(responses["shipping_status"])
    elif "order" in user_input:
        return random.choice(responses["order_status"])
    elif "product" in user_input or "category" in user_input:
        return random.choice(responses["product_category"])
    elif "shoes" in user_input:
        return random.choice(responses["shoes_range"])
    elif "trouser" in user_input:
        return random.choice(responses["trouser_range"])
    elif "shirt" in user_input:
        return random.choice(responses["shirt_range"])
    else:
        return random.choice(responses["default"])

# Chatbot interaction loop
print("Chatbot: Hi! Welcome to our online store. How can I assist you today?")
while True:
    user_input = input("You: ")
    response = generate_response(user_input)
    print("Chatbot:", response)
    if(response in ["Thank you for visiting our store. Have a great day!", "Goodbye! Come back soon!"]):
        break