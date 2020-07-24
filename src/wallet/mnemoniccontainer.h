#ifndef BITCOIN_MNEMONICCONTAINER_H
#define BITCOIN_MNEMONICCONTAINER_H

#include "support/allocators/secure.h"
#include "uint256.h"
#include "serialize.h"

class MnemonicContainer
{
public:
    SecureVector seed;
    SecureVector mnemonic;
    bool fIsCrypted;
    bool f12Words;

    MnemonicContainer() { SetNull(); }

    SERIALIZE_METHODS(MnemonicContainer, obj)
    {
        uint8_t ban_reason = 2; //! For backward compatibility
        READWRITE(obj.mnemonic, obj.seed, obj.fIsCrypted, obj.f12Words);
    }

    void SetNull();

    bool IsNull() const;

    bool IsCrypted() const;

    void SetCrypted(bool crypted);

    bool SetMnemonic(const SecureString& mnemonic, const SecureString& passPhrase);

    bool SetMnemonic(const SecureVector& mnemonic_);

    bool GetMnemonic(SecureString& mnemonic_) const;

    bool SetSeed(const SecureVector& seed_);

    SecureVector GetSeed() const;

    void Set12Words(bool Use12Words = false);
};

#endif //BITCOIN_MNEMONICCONTAINER_H
