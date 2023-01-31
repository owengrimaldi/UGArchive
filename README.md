# UGArchive

UGArchive is my personal archive of school projects, notes, and other small programs written during my time in undergraduate studies at the University of Notre Dame.

## Crimes in Chicago (Spring 2022)

Engineering Computing was my first foray into computer science, taken in my second semester of freshman year. The class consisted of learning the basics of programming in Python and applying these basics towards several projects of varying length.

Of these projects, the most notable is my final project for the class: Crimes in Chicago. Using a publicly available API that tracks 1000 of the most recent crimes from the city of Chicago, I alongside my partner Kyle Newman created a Jupyter Notebook that plotted these crimes in an interactive map for users. The project contains 3 variations of maps, allowing for users to interact with crimes based on the type of crime, the community area they occurr in, and density of crimes.

<img src="https://user-images.githubusercontent.com/67028882/215879741-f407a81c-d469-418f-ba6b-ae549314307c.png" width="300" height="300"><img src="https://user-images.githubusercontent.com/67028882/215880765-484e4685-c4f0-43b1-aa38-1ab84ea5aaf7.png" width="300" height="300"><img src="https://user-images.githubusercontent.com/67028882/215880779-a43cf659-c286-4c30-b54b-69e0031ead04.png" width="300" height="300">

In addition to the interactive maps, we also created some simple plots using the crime data to produce some insights about the frequency of certain crimes and more specific dives into community areas. This project was very heavily reliant on data parsing and handling, which offered great experience for future courses.

<img src="https://user-images.githubusercontent.com/67028882/215884076-d052a078-e4f9-459b-80c8-7ff2d5c81339.png" width="300" height="300">

As for usage, the notebook runs the user through each kernel with explanations and comments as to how the API data is parsed, analyzed, and put into interactive maps for consumption.

## Conway's Game of Life

In the same semester as Engineering Computing (Spring 2022), I also took a class called Fundamentals of Computing. This class was meant to be taken a semester later, but I opted to take it early to better mesh my knowledge of Python with fundamentals from C. The class covered much of the basics also taught in Engineering Computing, such as basic loops but also went into depth about memory management, external libraries, and even graphics libraries made in-house.

Conway's Game of Life was by far one of the most difficult programs I had ever written in up to this point. The goal of the project was to recreate a fully functional version of the classic Conway's Game of Life in C, a mathematical game revolving around tiles on a board acting through stages of natural selection. Each tile has conditions as to whether or not they become alive, stay alive, and die set about how many alive tiles surround them. With these conditions, you can create cool scenes where tiles generate other tiles, make flying ships, flicker in cool patterns, move around like cells, and more!

The program allows you to enter commands from both files and the executable, creating a scene before allowing you to play turn-by-turn or play continuously. With these features, you can recreate any of the many possible structures and concepts.
<img src="https://user-images.githubusercontent.com/67028882/215889155-4b9fd97e-a5a7-4a5e-a5ea-b0ed5a5f8539.png" width="113" height="362">

Below are two of the custom scenes I created for this project, the first being patterns of repetitive movements and the second being "flyers" who move across the screen.


https://user-images.githubusercontent.com/67028882/215888885-4e11ec50-a1a5-4869-8fd4-f6a5abbb6337.mp4

https://user-images.githubusercontent.com/67028882/215888896-154d5fa9-87c5-4b12-abe7-dddf4966b844.mp4



