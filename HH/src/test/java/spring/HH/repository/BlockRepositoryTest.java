package spring.HH.repository;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import spring.HH.domain.Block;

import java.time.LocalDate;
import java.util.List;

import static org.assertj.core.api.Assertions.*;
import static org.junit.jupiter.api.Assertions.*;

@SpringBootTest
class BlockRepositoryTest {

    @Autowired
    private BlockRepository blockRepository;

    @Test
    public void crud() {

        //given
        Block block = new Block();
        block.setName("martin");
        block.setReason("Not familiar");
        block.setStartDate(LocalDate.now());
        block.setEndDate(LocalDate.now());

        blockRepository.save(block);

        //when
        List<Block> blocks = blockRepository.findAll();

        //then
        assertThat(blocks.size()).isEqualTo(1);
        assertThat(blocks.get(0).getName()).isEqualTo("dennis");
        assertThat(blocks.get(1).getName()).isEqualTo("sophia");
        assertThat(blocks.get(2).getName()).isEqualTo("martin");
    }

}