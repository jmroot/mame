//**************************************************************************
//  TYPE DEFINITIONS
//**************************************************************************

struct l7a1045_voice
{
	/*
	l7a1045_voice() :
		pos(0),
		frac(0)
	{
		memset(regs, 0, sizeof(UINT32)*8);
	}

	UINT32 regs[8];
	UINT32 pos;
	UINT32 frac;
	*/
};

// ======================> l7a1045_sound_device

class l7a1045_sound_device : public device_t,
							public device_sound_interface
{
public:
	l7a1045_sound_device(const machine_config &mconfig, const char *tag, device_t *owner, UINT32 clock);
	~l7a1045_sound_device() { }

//	void set_base(INT8* base) { m_base = base; }

	DECLARE_WRITE16_MEMBER( l7a1045_sound_w );
	DECLARE_READ16_MEMBER( l7a1045_sound_r );

protected:
	// device-level overrides
	virtual void device_start();

	// sound stream update overrides
	virtual void sound_stream_update(sound_stream &stream, stream_sample_t **inputs, stream_sample_t **outputs, int samples);

private:
	sound_stream *m_stream;
//	l7a1045_voice m_voice[32];
//	UINT16     m_key;
//	INT8*      m_base;

	UINT16 m_audiochannel;

	struct l7a1045_48bit_data {
		UINT16 dat[3];
	};

	l7a1045_48bit_data m_audiodat[0x10000];

	DECLARE_WRITE16_MEMBER(l7a1045_sound_select_w);
	DECLARE_WRITE16_MEMBER(l7a1045_sound_data_02_w);
	DECLARE_WRITE16_MEMBER(l7a1045_sound_data_04_w);
	DECLARE_WRITE16_MEMBER(l7a1045_sound_data_06_w);

	DECLARE_READ16_MEMBER(l7a1045_sound_port_0004_r);
	DECLARE_READ16_MEMBER(l7a1045_sound_port_0006_r);


};

extern const device_type L7A1045;
