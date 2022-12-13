
# F-Engine 
F-Engine is a very simple, text based (make your own adventure) cross-platform game engine written in C++.

## Coding style:
For the coding style, we followed the standard defined by [google](https://google.github.io/styleguide/cppguide.html).

## Installation:
In order to build the application use CMake & Ninja.
- [Download & install cmake](https://cmake.org/download/)
- [Download & install Ninja](https://ninja-build.org/)
- Run the following script in CMD / linux terminal:

```sh
git clone https://github.com/rdavid22/mosze-2022-fengine.git
cmake -B build .
cd build
cmake --build .
./RunEngine
```

## Run tests:
This project uses Google tests. After building the application, 
we can run the test cases with the command: ```.\google_tests.exe```

## To make your game:
In order to build your own game, you have to modify the frames.json file as the followings:
```
{
   "frames":[
      {
         "id":1, <--- frame id: should be unique.
         "text":"Welcome to my game! Today's ElfMcSkidy's birthday! Would you like to come?",
         "answers":[  <--- possible answers
            {
               "reply":"Yes",
               "frame_id":2  <--- determines where the next conversation should go if user picks this answer.
            },
            {
                "reply":"No",
                "frame_id":3
            }
         ]
      },
      {
         "id":2, <--- if player choosen the answer "Yes", it will see this conversation.
         "text":"I'm glad! Are you hungry?",
         "answers":[
            {
               "reply":"Yes",
               "frame_id":4
            }
         ]
      }
    }
```