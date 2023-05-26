QUESTIONS = [
    'Do you have cough?',
    'Do you have a sore throat?',
    'Do you have a fever?',
    'Are you noticing any unexplained excessive sweating?',
    'Do you have an itchy throat?',
    'Do you have a runny nose?',
    'Do you have a stuffy nose?',
    'Do you have a headache?',
    'Do you feel tired without actually exhausting yourself?'
]

THRESHOLD = {
    'Mild': 30,
    'Severe': 50,
    'Extreme': 75
}

def expertSystem(questions, threshold):
    score = 0

    for question in questions:
        print(question+" (Y/N) ")
        ans = input("> ")
        if ans.lower() == 'y':
            print('On a scale of 1-10 how bad is it ?')
            ip = input('> ')
            while ((not ip.isnumeric()) or int(ip) < 1 or int(ip) > 10):
                print('Enter a valid input !')
                ip = input('> ')
            score += int(ip)

    print("\n\n")

    if score >= threshold['Extreme']:
        print("You are showing symptoms of having EXTREME COVID-19")
        print("Please call +91 8112233445 immediately to immediate assistance")
        print("Based on your symptoms, You will need Immediate Hospitalization")

    elif score >= threshold['Severe']:
        print("Based on your answers You are showing Symptoms of SEVERE COVID-19")
        print("You are advised to contact a COVID-19 Specialist ASAP")
        print("You are prescribed with Favipriavir, Dolo 650 / Crocin 500, Paracetamol, Brufane")
        print("Also coduct a COVID-19 Lab Test ASAP at your own convenience as this might be a false Positive\n\n")
        print("Lab Testing : https://www.metropolisindia.com/parameter/pune/covid-19-rt-pcr-test")

    elif score >= threshold['Mild']:
        print("Based on your answers You are showing Symptoms of VERY MILD COVID-19")
        print("Please Isolate yourself Immediately on a precautionary basis")
        print("As this has a possibility of being a false positive , please consider testing yourself")
        print("At home testing using Self-Testing kits is recommended , but you can get Lab Tests as well\n\n")
        print("Self testing : https://www.flipkart.com/mylab-coviself-covid-19-rapid-antigen-test-kit/p/itm4d34ea09cad97")
        print("Lab Testing : https://www.metropolisindia.com/parameter/pune/covid-19-rt-pcr-test")

    else:
        print("You are Showing NO Symptoms of COVID-19")
        print("This might be a false negative, If you feel unsure , please get Tested")
        print("As this has a possibility of being a false negative , please consider testing yourself")
        print("At home testing using Self-Testing kits is recommended\n\n")
        print("Self testing : https://www.flipkart.com/mylab-coviself-covid-19-rapid-antigen-test-kit/p/itm4d34ea09cad97")

    print("\n\nFor any further queries visit : https://www.aarogyasetu.gov.in/\n\n")

print("\n\n\t\tWelcome To The COVID-19 EXPERT SYSTEM\n")
print("\tNote : Please answer the following questions very honestly\n\n")
expertSystem(QUESTIONS,THRESHOLD)