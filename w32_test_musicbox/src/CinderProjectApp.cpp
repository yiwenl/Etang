#include "cinder/app/AppBasic.h"
#include "cinder/audio/Output.h"
#include "cinder/audio/Callback.h"
#include "cinder/Rand.h"
#include "cinder/CinderMath.h"
#include "cinder/Cinder.h"
#include "cinder/audio/PcmBuffer.h"

using namespace ci;
using namespace ci::app;

const uint32_t gFreqs[] = { 261, 330, 392, 493, 523, 659, 783 };
const uint32_t gFreqCount = 7;

class SineWave {
 public:
	SineWave( uint32_t freq, float duration );
	~SineWave() {}
	void getData( uint64_t inSampleOffset, uint32_t inSampleCount, ci::audio::Buffer32f *ioBuffer );
 private:
	float gen_sample(int n);
	float prev_sample;
	uint32_t mFreq;
	float mDuration;
};

class AudioGenerativeAdvancedApp : public AppBasic {
 public:
	void setup();
	void mouseDown( MouseEvent event );
	void draw();
	
};

void AudioGenerativeAdvancedApp::setup()
{
}

void AudioGenerativeAdvancedApp::mouseDown( MouseEvent event )
{
	int idx = ( event.getX() / (float)getWindowWidth() ) * gFreqCount;
	
	uint32_t freq = gFreqs[idx];
	audio::Output::play( audio::createCallback( new SineWave( freq, 1.0 ), &SineWave::getData, true ) );

	idx = ( event.getY() / (float)getWindowHeight() ) * gFreqCount;
	freq = gFreqs[idx];
	audio::Output::play( audio::createCallback( new SineWave( freq, 1.0 ), &SineWave::getData, true ) );
}

void AudioGenerativeAdvancedApp::draw()
{
	glClearColor( 0.1f, 0.1f, 0.1f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

SineWave::SineWave( uint32_t freq, float duration ) 
	: mFreq( freq ), mDuration( duration )
{
	prev_sample = 0.0;
}
float SineWave::gen_sample(int n)
{
	static float hgain[12] = {0.1, 0.05, 0.025, 0.0125, 0.0625, 0.003125, 0.0015625, 0.0015625, 0.0015625, 0.0015625, 0.0015625, 0.0015625};
	float val;

	val = 0.8*prev_sample;
	for (int i=0;i<12;i++)
		val += 0.16*hgain[i]*ci::math<float>::sin( (i+1)*n * ( mFreq / 44100.0f ) * 2.0f * M_PI );
	val *= (1.0f-((n/44100.0f) / mDuration)*(n/44100.0f) / mDuration);
	prev_sample = val;
	return val;
}
void SineWave::getData( uint64_t inSampleOffset, uint32_t inSampleCount, ci::audio::Buffer32f *ioBuffer )
{
	if( ( inSampleOffset / 44100.0f ) > mDuration ) {
		ioBuffer->mDataByteSize = 0;
		return;
	}
	
	uint64_t idx = inSampleOffset;
	
	for( int  i = 0; i < inSampleCount; i++ ) {
		
		float val = gen_sample(idx);
		
		ioBuffer->mData[i*ioBuffer->mNumberChannels] = val;
		ioBuffer->mData[i*ioBuffer->mNumberChannels + 1] = val;
		idx++;
	}
}

CINDER_APP_BASIC( AudioGenerativeAdvancedApp, RendererGl )
