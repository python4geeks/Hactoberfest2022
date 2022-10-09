import turtle
car_scr = turtle
car_scr.color('black')
car_scr.Screen().bgcolor("#ABEBC6")

def Draw_Car(i,j):
    # Drawing the Upper Body
    car_scr.fillcolor("#2980B9")
    car_scr.penup()
    car_scr.goto(i,j)
    car_scr.pendown()
    car_scr.begin_fill()
    car_scr.forward(370)
    car_scr.left(90)
    car_scr.forward(50)
    car_scr.left(90)
    car_scr.forward(370)
    car_scr.left(90)
    car_scr.forward(50)
    car_scr.end_fill()

    #Draw the Windows
    car_scr.fillcolor("#D5DBDB")
    car_scr.penup()
    car_scr.goto(i+100, 50)
    car_scr.pendown()
    car_scr.begin_fill()
    car_scr.setheading(45)
    car_scr.forward(70)
    car_scr.setheading(0)
    car_scr.forward(100)
    car_scr.setheading(-45)
    car_scr.forward(70)
    car_scr.setheading(90)
    car_scr.end_fill()
    car_scr.penup()
    car_scr.goto(i+200, 50)
    car_scr.pendown()
    car_scr.forward(49.50)

    # Draw the two wheels
    car_scr.penup()
    car_scr.goto(i+100, -10-j)
    car_scr.pendown()
    car_scr.color('black')
    car_scr.fillcolor('black')
    car_scr.begin_fill()
    car_scr.circle(20)
    car_scr.end_fill()
    car_scr.penup()
    car_scr.goto(i+300, -10-j)
    car_scr.pendown()
    car_scr.color('black')
    car_scr.fillcolor('black')
    car_scr.begin_fill()
    car_scr.circle(20)
    car_scr.end_fill()

Draw_Car(-200,0)

car_scr.done()
Footer
© 2022 GitHub, Inc.
Footer navigation
Terms
