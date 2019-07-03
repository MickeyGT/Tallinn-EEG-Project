import numpy as np
import sys

args = sys.argv[1:]

fs = 100                                # Sampling rate (1000 Hz)
#data = np.random.uniform(0, 100, 1024)  # 2 sec of data b/w 0.0-100.0

data = args

#print (data)

# Get real amplitudes of FFT (only in postive frequencies)
fft_vals = np.absolute(np.fft.rfft(data))

# Get frequencies for amplitudes in Hz
fft_freq = np.fft.rfftfreq(len(data), 1.0/fs)

# Define EEG bands
eeg_bands = {'Theta': (4, 8),
             'Alpha': (8, 12),}

# Take the mean of the fft amplitude for each EEG band
eeg_band_fft = dict()
for band in eeg_bands:  
    freq_ix = np.where((fft_freq >= eeg_bands[band][0]) & 
                       (fft_freq <= eeg_bands[band][1]))[0]
    #print(freq_ix)
    eeg_band_fft[band] = np.mean(fft_vals[freq_ix])


print (eeg_band_fft)

# Plot the data (using pandas here cause it's easy)
#import pandas as pd
#df = pd.DataFrame(columns=['band', 'val'])
#df['band'] = eeg_bands.keys()
#df['val'] = [eeg_band_fft[band] for band in eeg_bands]
#ax = df.plot.bar(x='band', y='val', legend=False)
#ax.set_xlabel("EEG band")
#ax.set_ylabel("Mean band Amplitude")

#print ("asdf")

