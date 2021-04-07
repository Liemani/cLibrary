#ifndef	T_PRIMITIVEPAIR_H
#define T_PRIMITIVEPAIR_H



typedef struct		s_primitivePair t_primitivePair;
typedef struct		s_primitivePair
{
	void			*key;
	void			*value;
	void			(*freeKey)(void **key);
	void			(*freeValue)(void **value);
	void			(*descriptionKey)(void *key);
	void			(*descriptionValue)(void *value);
};



t_primitivePair	*newPrimitivePair(void *key,
		void *value,
		void (*freeKey)(void **key),
		void (*freeValue)(void **value),
		void (*descriptionKey)(void *key),
		void (*descriptionValue)(void *value));
void	freePrimitivePair(t_primitivePair **pair);
void	descriptionPair(t_primitivePair *pair);



#endif
