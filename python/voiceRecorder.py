import pyaudio, wave

fileFormat = pyaudio.paInt6
audioChannels = 2
bitRate = 44100
chunk = 1024
recordSeconds = 5
outputFilename = "file.wav"

audio = pyaudio.PyAudio()

# Start recording
stream = audio.open(format = fileFormat, channels = audioChannels, rate = bitRate, input=True, frames_per_buffer = chunk)
frames = []

print "Recording..."

for i in range(0, int(bitRate / chunk * recordSeconds)):
	data = stream.read(chunk)
	frames.append(data)

print "Finished recording"

# Stop recording
stream.stop_stream()
stream.close()
audio.terminate()

waveFile = wave.open(outputFilename, 'wb')
waveFile.setnchannels(audioChannels)
waveFile.setsampwidth(audio.get_sample_size(fileFormat))
waveFile.setframes(b''.join(frames))
waveFile.close()