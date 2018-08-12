// hashBoardModel defines a few of the physical, unchanging parameters of a
// hashing board that is compatible with the obelisk mining software.
typedef struct hashBoardModel {
	// General string information.
	uint16_t chipsPerBoard;
	uint16_t enginesPerChip;
	uint16_t minStringVoltageLevel;
	uint16_t maxStringVoltageLevel;

	// Information for working with block headers for this algorithm.
	uint64_t headerSize;
	uint64_t nonceOffset;

	// Suggested parameters to use when operating the chips.
	uint64_t nonceRange;
} hashBoardModel;

// HASHBOARD_MODEL_SC1A defines the parameters for our SC1A hashing card.
const struct hashBoardModel HASHBOARD_MODEL_SC1A = {
	.chipsPerBoard = 15,
	.enginesPerChip = 64,
	.minStringVoltageLevel = 20,
	.maxStringVoltageLevel = 127,

	.headerSize = 80,
	.nonceOffset = 32,

	.nonceRange = 1 << 30
};
