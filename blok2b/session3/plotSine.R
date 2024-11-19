# generate and display a sinewave with wavelength = 2pi
curve(expr=sin, from=0, to=2*pi, xname = "t")
abline(h = 0, lty = 1, col = "gray")

# generate and display a sinewave with 
# wavelength = 1, frequency = 1 in the time domain, 
# thus, scale sine's wavelength to 1 second
sinewave_freq1 <- function(t) sin(t * 2*pi)
curve(expr=sinewave_freq1, from=0, to=2*pi, xname = "t")
abline(h = 0, lty = 1, col = "gray")

# display the sinewave once more with frequency = 1, 
# however, now within the time interval [0,1]
curve(expr=sinewave_freq1, from=0, to=1, xname = "t")
abline(h = 0, lty = 1, col = "gray")



# ________________ discrete time _________________
# In the previous example, 1 t represents with 1 second in the 
# continuous time domain. 
# In this example 1 t represents 1 sample in discrete time domain.

# samplerate = the number of samples per seconds
# Thus the wavelength of a sinewave with frequency = 1 equals the samplerate. 
samplerate = 44100
# In other words, the sinewave 'travels' one wave in 44100 discrete samples
# Compared to the sinewave example in the continuous time example, we here need 
# to 'spread it out over' 44100 samples. Herefore, within the calculation
# of the sine's output we divide t with the samplerate. 
sinewave <- function(t) sin(t * 2*pi / samplerate)
curve(sinewave, 0, samplerate, xname = "x")
abline(h = 0, lty = 1, col = "gray")


# now let's add the frequency, 
# a sinewave with frequency = 2 has a two time shorter wavelength compared to 
# a sinewave with frequency = 1
# thus at every sample step it 'travels two times faster', 
# therefore, we can simply multiply t with the frequency
frequency <- 2
sinewave <- function(t) sin(2* t * pi * frequency / samplerate)
curve(sinewave, add = TRUE, col = "violet")
frequency <- 10
sinewave <- function(t) sin(t * 2*pi * frequency / samplerate)
curve(sinewave, add = TRUE, col = "green")



# ________________ usage of phase _________________
# FINAL STEP --> 'transform to code'

# Let t indicate the index of a sample,
# then the equation is as follow (frequency is temporarily excluded 
# for the sake of simplicity).
# sample =  sin((t * 2 * pi) / samplerate)

# we can rewrite this function: 
# sample =  sin((t / samplerate) * 2 * pi)
#
# This results in a normalized value when t is in the range of [0, samplerate] 
# (t / samplerate) with interval t = [0, samplerate] 
# results in the interval [0, 1]
# e.g. samplerate = 44100
# 0 / 44100 = 0
# 44100 / 44100 = 1

# Because the sin function is a periodic function 
# Therefore, with t > samplerate in (t/samplerate) * 2 * pi, 
# the sine curve simply repeats.
# Thus (t / samplerate) can be viewed as the phase of the sinewave
# phase = t / samplerate

# Let's rewrite the equation.
# sample =  sin((t / samplerate) * 2 * pi)
# with phase = t / samplerate 
# results in: 
# sample = sin(phase * 2 * pi)

# To generate a sinewave with frequency = 1, 
# it is sufficient to keep track of the phase
# and to increase this at each sample step.
# phase += 1 / samplerate

# Now, let's also consider the frequency 
# To take the frequency into account, we can simply add it as follow.
# phase += frequency / samplerate

{
  samplerate = 44100
  numSamplesToDisplay = 100 # samplerate
  phase = 0
  frequency = 440 # 1
  phase_step = (frequency / samplerate)
  sinewave <- function(sample_index) {
    # here, phase = phase + phase_step
    phase = sample_index * phase_step
    return (sin(phase * 2*pi))
  }
  output = list()
  for (i in 1:numSamplesToDisplay) {
    output[i] = sinewave(i)
  }
  peakSampleI = 0.25 * samplerate
  output[peakSampleI]
  plot(c(1:numSamplesToDisplay), output)
}

# QUESTION: what are the benefits of working with a phase instead of time index? 





# TIP: what happens in both scenarios when you alter the frequency?

