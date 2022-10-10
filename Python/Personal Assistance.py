#all modules
import pyttsx3 #pip install pyttsx3
import speech_recognition as sr #pip install speechRecognition
import datetime
import wikipedia #pip install wikipedia
import webbrowser
import os
import smtplib

engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
#print(voices[1].id)
engine.setProperty('voice', voices[0].id)


def speak(audio):
    engine.say(audio)
    engine.runAndWait()


def wishMe():
    hour = int(datetime.datetime.now().hour)
    if hour>=0 and hour<12:
        speak("Good Morning!")

    elif hour>=12 and hour<18:
        speak("Good Afternoon!")   

    else:
        speak("Good Evening!")  

    speak("I am Jarvis, Sir. How may I help you?")       

def takeCommand():     
    r = sr.Recognizer()     
    with sr.Microphone() as source:         
        print("Listening...")
        r.pause_threshold = 1
        audio = r.listen(source)
  
    try:
        print("Recognizing...")    
        query = r.recognize_google(audio, language ='en-in')
        print(f"User said: {query}\n")
  
    except Exception as e:
        print(e)    
        print("Unable to Recognize your voice.")  
        return "None"     
    return query

def sendEmail(to, content):
    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.ehlo()
    server.starttls()
    server.login('youremail@gmail.com', 'your-password')
    server.sendmail('youremail@gmail.com', to, content)
    server.close()

if __name__ == "__main__": #main function
    wishMe()
    while True:
    # if 1:
        query = takeCommand().lower()

        # Logic for executing tasks based on query
        if 'search' in query:
            speak('Searching Wikipedia...')
            query = query.replace("wikipedia", "")
            results = wikipedia.summary(query, sentences=2)
            speak("According to Wikipedia")
            print(results)
            speak(results)

        elif 'open youtube' in query:
            speak("Opening youtube for you sir")
            webbrowser.open("youtube.com")

        elif 'open google' in query:
            speak("Opening google for you sir")
            webbrowser.open("google.com")

        elif 'open stack overflow' in query:
            speak("Opening stack overflow for you sir")
            webbrowser.open("stackoverflow.com")   

        elif 'play music' in query:
            music_dir = "" #Music directory path
            songs = os.listdir(music_dir)
            print(songs)    
            os.startfile(os.path.join(music_dir, songs[0]))

        elif 'the time' in query:
            strTime = datetime.datetime.now().strftime("%H:%M:%S")    
            speak(f"Sir, the time is {strTime}")

        elif 'open code' in query:
            codePath = "" #Code path
            os.startfile(codePath)

        elif 'email' in query:
            try:
                speak("What should I say?")
                content = takeCommand()
                to = "abc@gmail.com"    
                sendEmail(to, content)
                speak("Email has been sent!")
            except Exception as e:
                print(e)
                speak("Sorry Sir. I am not able to send this email")
                speak("I will make sure to troubleshoot this problem.")

        elif 'what are you doing' in query:
            speak("I got no plans today so I was resting.")

        elif 'rude' in query:
            speak("I'm sorry sir. Please accept my appology.")

        elif 'got any plans' in query:
            speak("No meetings or important tasks assigned for today. You can rest.")

        elif 'how are you' in query:
            speak("I'm feeling great sir, Thank you. What about you? How are you feeling today?")

        elif 'feeling good' in query:
            speak("Glad to hear that!")

        elif 'thank you' in query:
            speak("Glad I could be helpful.")

        elif 'you are smart' in query:
            speak("I know that. But thanks anyway.")
                
        #to exit from the program with a voice command
        elif 'go back to sleep' in query:
            speak("thank you for talking with me, have a good day.")
            exit()