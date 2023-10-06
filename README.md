# philosophers
Dijkstra's hungry philosophers

<img src="https://github.com/u413-284-si/philosophers/assets/66411482/50c2798b-31bc-4b23-a8af-585fa3f37d28" width="500" height="300">

## Intro
This project is an implementation of the popular *dining philosophers problem* formulated by Edsger Dijkstra in 1965 and further on elaborated by Tony Hoare.
A certain number of *n* philosophers are sitting at the same table. Between each philosopher is a fork resulting in *n* forks on the table. The dish served is a kind of spaghetti which has to be eaten with two forks. In this instance each philosopher can alternately think, eat or sleep. Most importantly a philosopher can only eat their spaghetti when they have two forks in their hands. Thus two forks will only be available when their two nearest neighbors are thinking or sleeping, not eating. After finishing eating, the philosopher will put down both forks making them available to his neighbours. 

The essence of the problem is to ensure that each philosopher has the opportunity to eat in time before starving to death - a scenario which is preferably to be avoided as one can imagine.

## Project overview

The goal of this project is to introduce the concept of processes, threads and multi-threaded programming. Each philosopher is being implemented as a thread which is competing with the other threads/philosophers for the same resources. In order to avoid race conditions mutexes will be used to secure the shared resources to allow for unambiguous handling. Furthermore the project encourages to code in an efficent manner so that the programm itself computes as fast as possible in order to avoid threads from staying too long in a state where they have not "eaten" leading to starvation.

Following a short summary of the topics covered by the project:

- multi-threaded programming
- data race conditions
- mutexes and associated libraries

## Installation and Usage

```
git clone git@github.com:u413-284-si/philosophers.git philo
cd philo
make
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
- number_of_philosophers: The number of philosophers and also the number
of forks.
- time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the sim-
ulation, they die.
- time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.
- time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
- number_of_times_each_philosopher_must_eat (optional argument): If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.


## Contact & contribute

To contact me and for feedback in order to fix bugs/improve the project you may write me a message to Discord u413q#6851. Or simply create a merge request ;)

