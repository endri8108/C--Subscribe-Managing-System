# GSM Subscriber Management System

A terminal program written in C for managing mobile phone subscribers and their operator history. I built it as a university programming project.

It comes with 100 sample subscribers. Each record holds personal details, the current operator plan and campaign, and the two previous operators with their plan dates.

## Features

**Managing the data**
- Add a subscriber
- Delete a subscriber
- Update subscriber information
- Search by national ID number or by first and last name

**Reports**
- **Operator changes:** list every subscriber who switched operators in a given year
- **Loyalty report:** find subscribers who stayed with the same operator across all three plans, with a count for each operator
- **Campaign popularity:** count subscribers per campaign and sort the campaigns from most to least popular (selection sort)

## How it works

- `data_set.h` defines the `subscriber` and `date` structs and a fixed array (`people[1000]`) filled with 100 sample records.
- `main.c` has the menu loop and one function per feature.
- All data lives in memory. Changes are lost when the program closes.

## Build and run

You need CMake and a C compiler.

```bash
mkdir build && cd build
cmake ..
cmake --build .
./C__Subscribe_Managing_System
```

Or compile it directly:

```bash
gcc main.c -o subscriber_system
./subscriber_system
```

## Notes

- Enter dates with `/` between the parts, for example `13/12/2025`.
- I developed it on macOS. It uses `unistd.h` (`sleep`) and `system("clear")`, so on Windows you need to replace them with `windows.h` (`Sleep`) and `system("cls")`.
- The menu layout uses a lot of tab characters, so it looks best in a wide terminal window.
