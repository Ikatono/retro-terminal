#ifndef H_912C6FF94CF84F02AE92045DBE91DD42
#define H_912C6FF94CF84F02AE92045DBE91DD42

#include <SDL3/SDL_audio.h>

namespace Audio
{
    struct AudioFile
    {
        public:
            SDL_AudioSpec spec;
            Uint8* audio_buf;
            Uint32 audio_len;
    };

    int init();
    int getSampleAudio(AudioFile* file);
}


#endif //H_912C6FF94CF84F02AE92045DBE91DD42